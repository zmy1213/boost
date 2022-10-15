#include<climits>
#include<assert.h>
#include<cfloat>
#include<iostream>
#include<boost/numeric/conversion/cast.hpp>
#include<boost/numeric/conversion/bounds.hpp>
using namespace std;
using namespace boost::numeric;
using namespace boost;
int main()
{
	int x = INT_MAX;
	cout << x << endl;
	cout << numeric_limits<int>::max() << endl;
	float y = FLT_MIN;
	cout << y << endl;
	cout << numeric_limits<float>::max << endl;


	cout << bounds<short>::lowest();//最小极值
	cout << bounds<short>::highest();//最大极值
	cout << bounds<short>::smallest();//最小正规值 整数是1，小数是绝对值最小值
	
	short s = bounds<short>::highest();
	int i = boost::numeric_cast<int>(s);;
	assert(i == s);
	try//numeric_cast只能应用于数字转型
	{
		char c = numeric_cast<char>(s);
	}
	catch(bad_cast &e)
	{
		cout << e.what() << endl;
	}
}
