#include<iostream>
#include<memory>
#include<assert.h>
#include<boost/pointer_to_other.hpp>
using namespace std;

int main()
{
	//原始指针的特征
	assert((is_same<pointer_traits<int*>::pointer, int*>::value));
	assert((is_same<pointer_traits<int*>::element_type, int>::value));
	assert((is_same<pointer_traits<int*>::rebind<char>, boost::pointer_to_other<int*,char>::type>::value));

	typedef shared_ptr<string> sptr;
	assert((is_same<pointer_traits<sptr>::difference_type, ptrdiff_t>::value));
	assert((is_same<pointer_traits<sptr>::rebind<char>, boost::pointer_to_other<sptr, char>::type>::value));

}
