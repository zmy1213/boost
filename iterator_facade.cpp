#include<iostream>
#include<boost/iterator/iterator_facade.hpp>
#include<vector>
using namespace std;
using namespace boost;
//在使用iterator_facade我们要规划迭代器的名称，再何种集合上迭代，迭代的对象，迭代便利的类型
//

template<typename T>
class vs_iterator :public boost::iterator_facade<vs_iterator<T>, T, boost::single_pass_traversal_tag>
{
private:
	vector<T>& v;
	size_t current_pos;
public:
	typedef boost::iterator_facade<vs_iterator<T>,T,single_pass_traversal_tag> super_type;
	typedef vs_iterator this_type;

	typedef typename super_type::reference reference;
	vs_iterator(vector<T>& _v, size_t pos = 0) :v(_v), current_pos(pos)
	{}
	vs_iterator(this_type const&other):v(other.v),current_pos(other.current_pos)
	{}
	void operator=(this_type const&other)
	{
		this->v = other.v;
		this->current_pos = other.current_pos;
	}
private:
	friend class boost::iterator_core_access;
	reference dereference()const
	{
		return v[current_pos];
	}
	void increment()
	{
		++current_pos;
	}
	bool equal(this_type const& other)const
	{
		return this->current_pos == other.current_pos;
	}
};
template<typename I,ptrdiff_t N=2>
class step_iterator :public iterator_facade<step_iterator<I>, typename iterator_value<I>::type const, single_pass_traversal_tag>
{
private:
	I m_iter;
public:
	typedef iterator_facade<step_iterator<I>, typename iterator_value<I>::type const, single_pass_traversal_tag> super_type;
	using this_type = step_iterator;
	using  typename super_type::reference;
	step_iterator(I x) :m_iter(x) {}
	step_iterator(this_type const& o) = default;
	this_type& operator=(this_type const& o) = default;
private:
	friend class boost::iterator_core_access;
	reference dereference()const
	{
		return *m_iter;
	}
	void increment()
	{
		advance(m_iter, N);
	}
	bool equal(step_iterator const& other)const
	{
		return m_iter == other.m_iter;
	}
};
int main()
{
	vector<int> v{ 1,2,3,4,5 };
	vs_iterator<int> vsi(v), vsi_end(v, v.size());
	*vsi = 9;
	copy(vsi, vsi_end, ostream_iterator<int>(cout, ","));

	char s[] = "12345678";
	copy(s, s + 8, ostream_iterator<char>(cout));
	cout << endl;
	step_iterator<char*>first(s), last(s + 8);
	copy(first, last, ostream_iterator<char>(cout));
}
