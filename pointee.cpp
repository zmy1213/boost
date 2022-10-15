#include<boost/pointee.hpp>
#include<iostream>
using namespace std;
using namespace boost;
//推到接引用类型
int main()
{
    //pointee 返回的是指针的类型
	assert((is_same<pointee<int*>::type, int>::value));
	assert((is_same<pointee<unique_ptr<int>>::type, int>::value));
	assert((is_same<pointee<string::iterator>::type, char>::value));

	typedef shared_ptr<int>P;
	P p(new int(10));
	pointee<P>::type v = *p;
	assert(v == 10);
}
