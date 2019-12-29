//学习函数模板
//2019.10.20 GM

#include<iostream>
using namespace std;

//函数模板
template <typename T>
inline T sum(T a, T b)    //函数模板也可以被定义为内联函数
{
	//typedef double T;  //错误：重新声明模板参数Type,不允许T重名
	return a + b;
}

//多个类型参数,平时这种用法很少
template <typename T1,typename T2,class T3>
T3 sum(T1 a, T2 b)
{
	//typedef double T;  //错误：重新声明模板参数Type,不允许T重名
	T3 tmp = a + b;
	return tmp;
}

int main()
{
	//模板函数
	//整型求和
	int a=sum<int>(111, 222);
	cout << a << endl;

	//单精度求和
	float f = sum<float>(1.234f, 4.567f);
	cout << f << endl;

	//双精度求和
	double d = sum<double>(1.234, 4.567);
	cout << d << endl;



	//多参数函数模板
	double d2 = sum<int, float,double>(100, 1.234f);
	cout << d2 << endl;



}