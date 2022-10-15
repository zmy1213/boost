#include<iostream>
#include<boost/get_pointer.hpp>

//实现原理
template<class T>T* get_pointer(T *p)
{
  return p;
}
template<class T>T* get_pointer(unique_Ptr<T> const &p)
{
  return p.get();
}
template<class T>T* get_pointer(shared_Ptr<T> const &p)
{
  return p.get();
}
