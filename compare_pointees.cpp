#include<iostream>
#include<boost/utility/compare_pointees.hpp>
#include<boost/scoped_ptr.hpp>
#include<assert.h>
#include<optional>

using namespace std;
using namespace boost;
int main()
{
	scoped_ptr<int> p1(new int(10));
	scoped_ptr<int> p2(new int(20));//类似于auto_ptr,不能转让指针的所有权限

	assert(!equal_pointees(p1, p2));
	assert(less_pointees(p1, p2));

	p2.reset();
	optional<string> op1, op2;//返回的值可以更多样化，可以赋予其无效值而不抛出异常
	assert(equal_pointees(op1, op2));
	op2 = "hello";
	assert(less_pointees(op1, op2));
}
