//学习模板递归
//2019.10.26 GM

#include<iostream>
using namespace std;

//示例一
template<typename T>
class A
{
private:
	A<void> a;   //进入了递归定义
};

//通过特化来终结递归定义
template<>
class A<void>
{
};


//示例二
//利用编译器编译求和
template<int N>
class Sum
{
public:
	enum//用枚举类型，因为用变量，它不会再编译期间推导值
	{
		value = N + Sum<N - 1>::value
	};
};

template<>
class Sum<0>
{
public:
	enum
	{
		value = 0
	};
};


//示例三   利用编译期实现二进制转十进制
//主模板
template<unsigned long N>
struct BinToDec
{
	static const unsigned val = BinToDec<N / 10>::val * 2 + N % 10;
};

template<>
struct BinToDec<0>  //特化
{
	static const unsigned val = 0;
};

void main()
{
	//利用编译期递归实现求和函数
	cout << Sum<100>::value << endl;

	//利用编译期递归实现二进制转十进制
	cout << BinToDec<10000>::val << endl;
}