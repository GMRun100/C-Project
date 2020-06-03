//学习STL与萃取技术相关的类
#include<iostream>
using namespace std;

int fun(int a)
{
	return a;
}

typedef int(*PFUN)(int a);   //函数指针类型
PFUN pfun; //函数指针


//仿函数
struct FUNO
{
	void operator()(int a)
	{}
};

class A {};
class B:A{};
class C :B {};
void main()
{

	//判断一个类型是否为空
	cout << is_void<void>::value << endl;
	cout << is_void<int>::value << endl;

	//判断是否是指针

	cout << is_pointer<int*>::value << endl;
	cout << is_pointer<void (*)(int,int)>::value << endl;  //函数指针

	//判断是否是函数类型
	//decltype返回变量的类型
	cout << is_function<decltype(fun)>::value << endl;
	cout << is_function<PFUN>::value << endl;  //函数指针
	cout << is_function<decltype(pfun)>::value << endl;
	cout << is_function<FUNO>::value << endl;   //仿函数类型

	//判断是否是数组类型
	cout << is_array<int[3]>::value << endl;
	cout << is_array<array<int,3>>::value << endl;  //array不属于数组 类型

	//判断一个类型是否是另一个类型的基类
	cout << is_base_of<int, int>::value << endl;
	cout << is_base_of<A, B>::value << endl;  //A是否是B的基类
	cout << is_base_of<A, C>::value << endl;  //A是否是C的基类


	//判断一个类型是否是对象类型
	//对象类型是与其关联的存储类型，包括除函数，引用和void之外的所有类型
	cout << is_object<int>::value << endl;
	cout << is_object<int(*)(int)>::value << endl;
	cout << is_object<int&>::value << endl;



}