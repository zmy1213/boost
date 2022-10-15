#include<iostream>
using namespace std;
#include<boost/pointer_cast.hpp>
#include<boost/scoped_ptr.hpp>
#include<boost/pointee.hpp>
#include<assert.h>
#include<boost/pointer_to_other.hpp>
#
using namespace boost;

//scopded_ptr这个智能指针只能在作用域里使用，不希望被转让。类似于auto_ptr 实现原理
pointer_cast
template<class T,class U>
inline T*static_pointer_cast(U*ptr)
{
	return static_cast<T*>(ptr);
}
template<class T,class U>
inline T* static_pointer_cast(U* ptr)
{
	return dynamic_cast<T*>(ptr);
}
template<class T, class U>
inline T* const_pointer_cast(U* ptr)
{
	return const_cast<T*>(ptr);
}
template<class T, class U>
inline T* const_pointer_cast(U* ptr)
{
	return const_cast<T*>(ptr);
}
template<class T, class U>
inline T* reinterpret_cast_pointer(U* ptr)
{
	return reinterpret_cast<T*>(ptr);
}
