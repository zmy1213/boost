#include<boost/indirect_reference.hpp>
#include<iostream>
#include<assert.h>
using namesapce std;
using namespace boost;
//与pointee 相似，但是返回的是引用
int main()
{
  assert(!is_same<indirect_reference<int*>::type,int&>::value);
}
