//学习模板形参的非类型参数
//2019.10.24 GM

#include<iostream>
using namespace std;

template <int len> //len为非类型参数
void test()
{
	int arr[len];
	cout << sizeof(arr) << endl;
}

//传入字符串
char strtmp[] = "hello world!";
template <char *str> 
void test2()
{
	
	cout << str << endl;
}

//传入整型引用
int i3 = 100;
template <int& i>
void test3()
{

	cout << i << endl;
}


//传入指针
int i4 = 100;
template <int* i>
void test4()
{

	cout << *i << endl;
}

//传入函数指针
void fun5(int a)
{
	cout << a << endl;
}
template <void(*pf)(int)>
void test5()
{

	pf(111);
}


void main()
{
	//实现了动态数组，由用户指定长度
	test<10>();
	test<20>();

	
	test2<strtmp>();   //strtmp必须为静态存储，而全局变量为静态存储
	
	test3<i3>();

	test4<&i3>();

	test5<fun5>();


}
