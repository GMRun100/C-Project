//ѧϰ��ģ��
//2019.10.22 GM

#include<iostream>
using namespace std;
#include"tp2.h"
#include"tp3.h"
#include"tp4.h"
#include"tp5.h"
//ģ����
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

//1.��ͨ��̳�ģ����
class B :public A<int>
{
public:
	B(int _a,float _b) :A(_a),b(_b){}   //�����ʼ���б�

	float b;
	void printB()
	{
		cout << "B" << b << endl;
	}
};






void main()
{
	//1.��ͨ��̳�ģ����
	B b(11, 1.234f);
	b.printA();
	b.printB();

	//2.��ģ��̳���ͨ��
	B2<float> b2(11, 1.234f);
	b2.printA();
	b2.printB();

	//3.��ģ��̳���ģ��
	B3<int,float> b3(11, 1.234f);
	b3.printA();
	b3.printB();

	//4.��ģ��̳�ģ����
	B4<float> b4(11, 1.234f);
	b4.printA();
	b4.printB();

	//5.��ģ��̳����Ͳ���
	B5<float,A5<int>> b5(11, 1.234f);
	b5.printA();
	b5.printB();

}