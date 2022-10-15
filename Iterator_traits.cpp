#include<iostream>
#include<boost/iterator/iterator_traits.hpp>
#include<assert.h>
using namespace std;
using namespace boost;
//五种值类型
//iterator_category
//value_type
//reference 
//pointer
//diffence_type

template<class Iterator>
struct Iterator_value
{
	typedef typename iterator_traits<Iterator>::value_type type;
};
template<class Iterator>
struct Iterator_reference
{
	typedef typename iterator_traits<Iterator>::reference type;
};
template<class Iterator>
struct Iterator_category
{
	typedef typename iterator_traits<Iterator>::category type;
};
int main()
{
	
	using I = int*;
	assert((is_same<Iterator_value<I>::type, int>::value));
	assert((is_same<Iterator_reference<I>::type, int&>::value));
	assert((is_same < Iterator_category<I>::type, random_access_iterator_tag >::value));

}
