//学习命名空间
//2019.09.14 GM 
#include<iostream>
using namespace std;

int a = 10;
namespace A
{
	int a = 100;
	int b = 200;
	//命名空间可以嵌套
	namespace B
	{
		int a = 101;
		int b = 201;
		int m = 300;
	}
	namespace
	{
		int z = 1000;
	}
}

int main()
{
	cout << a << endl;
	cout << A::a << endl;
	cout << A::B::b << endl;

	//声明使用B命名空间
	using namespace A::B;
	cout << b << endl;    //不用显式的指明命名空间
	cout << m << endl;

	//使用匿名命名空间中的变量
	cout << A::z << endl;

	return 0;
}