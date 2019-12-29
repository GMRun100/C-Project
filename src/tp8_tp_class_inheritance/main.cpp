//学习类模板
//2019.10.22 GM

#include<iostream>
using namespace std;
#include"tp2.h"
#include"tp3.h"
#include"tp4.h"
#include"tp5.h"
//模板类
template <typename T>
class A
{
public:
	A(T _a) :a(_a){}

	T a;
	void printA()
	{
		cout << "A" << a << endl;
	}
};

//1.普通类继承模板类
class B :public A<int>
{
public:
	B(int _a,float _b) :A(_a),b(_b){}   //构造初始化列表

	float b;
	void printB()
	{
		cout << "B" << b << endl;
	}
};






void main()
{
	//1.普通类继承模板类
	B b(11, 1.234f);
	b.printA();
	b.printB();

	//2.类模板继承普通类
	B2<float> b2(11, 1.234f);
	b2.printA();
	b2.printB();

	//3.类模板继承类模板
	B3<int,float> b3(11, 1.234f);
	b3.printA();
	b3.printB();

	//4.类模板继承模板类
	B4<float> b4(11, 1.234f);
	b4.printA();
	b4.printB();

	//5.类模板继承类型参数
	B5<float,A5<int>> b5(11, 1.234f);
	b5.printA();
	b5.printB();

}