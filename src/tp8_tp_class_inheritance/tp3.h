#pragma once
#include<iostream>
using namespace std;


template <typename T>
class A3
{
public:
	A3(T _a) :a(_a) {}

	T a;
	void printA()
	{
		cout << "A3" << a << endl;
	}
};
//3.类模板继承类模板
template <typename T1, typename T2>
class B3:public A3<T1>
{
public:
	B3(T1 _a,T2 _b) :A3<T1>(_a),b(_b) {}

	T2 b;
	void printB()
	{
		cout << "B3" << b << endl;
	}
};
