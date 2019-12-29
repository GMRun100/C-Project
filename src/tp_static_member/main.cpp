//学习模板的静态成员
//2019.10.22 GM

#include<iostream>
using namespace std;

template<typename T>
class A
{
public:
	static int s; //不依赖模板类型的静态成员
	static T s2;
};

//静态成员初始化
template<typename T>
int A<T>::s = 111;//模板类静态成员的初始化，对任意类型T都有一份通用的值

//静态成员特化
template<>
int A<int>::s = 222;   //只针对int类型有效

template<>
float A<float>::s2 = 1.234f;  //只能特化

template<>
char A<char>::s2 = 'A';  //只能特化


void main()
{
	//不依赖模板类型的静态成员
	cout << A<float>::s << endl;
	cout << A<char>::s << endl;
	cout << A<double>::s << endl;
	cout << A<int>::s << endl;

	//依赖模板类型的静态成员
	cout << A<float>::s2 << endl;
	cout << A<char>::s2 << endl;


}