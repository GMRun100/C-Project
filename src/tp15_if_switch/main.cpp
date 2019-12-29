//学习编译期if switch结构
//2019.10.26 GM 

#include<iostream>
using namespace std;

//主模板
template<bool b>  //非类型参数
struct If   //注意这里不能用if关键字
{};


//全特化，为真的时候执行
template<>  
struct If<true>
{
	static void fun()
	{
		cout << "为真执行语句！" << endl;
	}
};
//全特化，为假的时候执行
template<>
struct If<false>
{
	static void fun()
	{
		cout << "为假执行语句！" << endl;
	}
};

//switch主模板
template<int Case>
struct Switch
{
	static void f()
	{
		cout << "执行default语句" << endl;
	}
};

//全特化，Case为1时执行
template<>
struct Switch<1>
{
	static void f()
	{
		cout << "执行Case1语句" << endl;
	}
};

//全特化，Case为2时执行
template<>
struct Switch<2>
{
	static void f()
	{
		cout << "执行Case2语句" << endl;
	}
};

void main()
{
	//编译期的if结构
	If<true>::fun();
	If<false>::fun();

	//编译期的switch结构
	Switch<1>::f();
	Switch<2>::f();
	Switch<99>::f();

}