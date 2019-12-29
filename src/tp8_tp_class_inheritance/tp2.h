#pragma once
#include<iostream>
using namespace std;

class A2
{
private:
	int a;
public:
	A2(int _a) :a(_a) {}


	void printA()
	{
		cout << "A2" << a << endl;
	}
};

//2.模板类继承普通类
template <typename T>
class B2 :public A2
{
public:
	B2(int _a, T _b) :A2(_a), b(_b) {}

	T b;
	void printB()
	{
		cout << "B2" << b << endl;
	}
};