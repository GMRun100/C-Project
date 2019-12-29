//学习模板形参为模板参数的情况
//2019.10.26 GM

#include<iostream>
using namespace std;

template<typename T>
class A
{
public:
	void print();
};

template<typename T>
void A<T>::print()
{
	cout << "A" << endl;
}

template<template<typename X> typename T>
class B
{
private:
	T<int> a;
public:
	void print();
};
template<template<typename X> class T>
void B<T>::print()
{
	cout << "B" << endl;
		a.print();
}

void main()
{
	//用模板实例化
	B<A> b;
	b.print();
}