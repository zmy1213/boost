#include<iostream>
#include<boost/iterator_adaptors.hpp>
#include<boost/static_assert.hpp>
#include<boost/type_traits/is_pointer.hpp>
#include<boost/iterator/iterator_traits.hpp>
#include<vector>
using namespace std;
using namespace boost;

//Adaptee 必须是可拷贝构造和可赋值的
template<typename P>
class array_iter :
	public iterator_adaptor<array_iter<P>, P, boost::use_default, 
	random_access_traversal_tag>
{
	
	BOOST_STATIC_ASSERT(boost::is_pointer<P>::value);
public:
	typedef typename array_iter::iterator_adaptor_ super_type;
	array_iter(P x) :super_type(x)
	{}
};

template<typename T>
class delta_iterator :public iterator_adaptor < delta_iterator<T>, T, typename std::iterator_traits<T>::value_type,
	single_pass_traversal_tag, typename std::iterator_traits<T>::value_type const>
{
private:
	friend class boost::iterator_core_access;
	typedef delta_iterator this_type;
	typedef typename this_type::iterator_adaptor_  super_type;
	typename super_type::value_type m_value;
public:
	explicit delta_iterator(const T& iter) :super_type(iter), m_value(0)
	{}
private:
	using this_type::base;
	using this_type::base_reference;
	typename this_type::reference dereference()const
	{
		return m_value + *base();
	}
	void increment()
	{
		m_value += *base();
		++base_reference();
	}
};
int main()
{
	int a[10] = { 1,2,3 };
	array_iter<int*> start(a), finish(a + 10);
	
	copy(start, start+10, ostream_iterator<int>(cout, ","));
	cout << endl;

	vector<int> v{ 1,2,3 };
	typedef delta_iterator<decltype(v.cbegin())>delta_iter;
	delta_iter start1(v.begin()), finish1(v.end());
	copy(start1, finish1, ostream_iterator<int>(cout, ","));
 }
