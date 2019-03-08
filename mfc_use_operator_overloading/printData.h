#pragma once
#include <iostream>

using namespace std;


//下面是一个函数重载的例子
class printData
{
public:
	printData();
	~printData();

	//函数重载：函数的行为会随着参数的类型不同而不同
	void print(int i)
	{
		cout << "整数为：" << i << endl;
	}

	void print(double f)
	{
		cout << "浮点数为：" << f << endl;
	}

	void print(char c[])
	{
		cout << "字符串为：" << c << endl;
	}

};

