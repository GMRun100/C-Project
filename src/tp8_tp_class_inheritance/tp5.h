#pragma once

#include<iostream>
using namespace std;

template <typename T>
class A5
{
public:
	A5(T _a) :a(_a) {}

	T a;
	void printA()
	{
		cout << "A5" << a << endl;
	}
};

//5.类模板继承类型参数
template <typename T1,typename T2>
class B5 :public T2
{
public:
	B5(T2 _a, T1 _b) :T2(_a), b(_b) {}

	T1 b;
	void printB()
	{
		cout << "B5" << b << endl;
	}
};
