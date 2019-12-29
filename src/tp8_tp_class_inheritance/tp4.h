#pragma once

#pragma once
#include<iostream>
using namespace std;


template <typename T>
class A4
{
public:
	A4(T _a) :a(_a) {}

	T a;
	void printA()
	{
		cout << "A4" << a << endl;
	}
};
//4.类模板继承模板类
template <typename T2>
class B4 :public A4<int>
{
public:
	B4(int _a, T2 _b) :A4<int>(_a), b(_b) {}

	T2 b;
	void printB()
	{
		cout << "B4" << b << endl;
	}
};
