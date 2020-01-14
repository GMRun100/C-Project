//2019.12.31 GM  学习仿函数
#include<iostream>
using namespace std;

int ncount = 0;

//输出最小值
int Min(const int& a, const int& b)
{
	ncount++;
	return a < b ? a:b;
}


//仿函数 1.它是struct或者class 2.()运算符重载
struct Min2
{
	typedef int ret_type;  //定义内部类型

	int  operator()(const int& a, const int& b)
	{
		m_ncount++;
		return a < b ? a : b;
	}
	static int m_ncount;   //保存Min2调用次数
};

int Min2::m_ncount = 0;


class Min3
{
public:
	int  operator()(const int& a, const int& b)
	{
		return a < b ? a : b;
	}
private:
	void(*pMin)(int a, int b);  //函数指针

};


void main()
{
	//正常的函数调用
	cout << "最小值是:" << Min(111, 222) << endl;

	//仿函数调用
	Min2 min2;  //定义一个结构体变量
	cout << "最小值是:" << min2(111, 222) << endl;   //对象的运算符成员函数
	cout << "最小值是:" << Min2()(111, 222) << endl;   //Min2()无名对象，直接调用
	cout << "最小值是:" << Min3()(111, 222) << endl;   //Min3()无名对象，直接调用
}