#include<boost/next_prior.hpp>
#include<iostream>
#include<boost/iterator/iterator_traits.hpp>
#include<list>
#include<assert.h>
using namespace std;
using namespace boost;

//简化代码如下 next prior 同理
//template<class T>
//inline T next(T x)
//{
//	return ++x;
//}
//
//template<class T,class Distance>
//inline T next(T x, Distance n)
//{
//	advance(x, n);
//	return x;
//}

template<typename I>
typename iterator_traits<I>::value_type
get_n(I& iter, int n)
{
	return *(next(iter, n));
}
int main()
{
	list<int> li{1,2,3,4};

	auto p1 = li.begin();
	auto p2 = li.end();

	assert(get_n(p1, 1) == 2);
	assert(get_n(p2, -2) == -4);
	assert(get_n(p2, -2) == 3);
	//由于list不是随机访问迭代器，可以设计前进n步的get_n
}
