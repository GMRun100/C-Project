//学习编译期for循环
//2019.10.26 GM

#include<iostream>
using namespace std;

template<int N>
struct For
{
	static void F()
	{
		cout << "循环的执行语句" << N << endl;
		For<N - 1>::F();
	}
};


//利用全特化来终止递归
template<>
struct For<0>
{
	static void F()
	{
		cout << "循环的执行语句" << 0 << endl;
	}
};


void main()
{
	For<5>::F();
}