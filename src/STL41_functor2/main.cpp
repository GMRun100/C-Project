#include<iostream>
#include<functional>
using namespace std;

//一元函数对象(仿函数)

//struct IsOdd
//{
//	bool operator()(int a)   //此处只有一个参数
//	{
//		return a % 2 == 1;
//	}
//
//};




struct IsOdd:public unary_function<int,bool>
{
	result_type operator()(argument_type a)   //此处只有一个参数
	{
		return a % 2 == 1;
	}

};


//二元函数对象
//struct Min
//{
//	int  operator()(const int& a, const int& b)
//	{
//		return a < b ? a : b;
//	}
//};


//二元函数对象，继承的方法
struct Min:public binary_function<const int & ,const int &,int>
{
	result_type  operator()(first_argument_type a, second_argument_type b)
	{
		return a < b ? a : b;
	}
};


void main()
{
	//定义一个变量
	IsOdd::argument_type a = 111;
	IsOdd::result_type ret = IsOdd()(111);
	cout << "是否是奇数:" << ret << endl;

	Min::first_argument_type a2 = 111;

	Min::second_argument_type b2 = 222;
	Min::result_type c = Min()(a2, b2);
	cout << "最小值是:" << c << endl;
	


}