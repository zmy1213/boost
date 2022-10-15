#include<iostream>
#include<assert.h>
#include<boost/pointer_to_other.hpp>
using namespace std;

//实现原理
template<class T,class U>
struct pointer_to_other;
template<class T, class U>
struct pointer_to_other <T*, U>
{
	typedef U* type;
};
template<class T, class U, template<class> class Sp>
struct pointer_to_other<Sp<T>, U>
{
	typedef Sp<U> type;
};
