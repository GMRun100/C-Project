//学习typeid的用法
//2019.09.13 GM 

#include <iostream>
using namespace std;
#include<atlstr.h>

struct A
{

};
int main()
{
	//直接输出类型
	cout << typeid(int).name() << endl;

	//输出结构体类型
	cout << typeid(A).name() << endl;

	//输出字符串类型
	cout << typeid("abcde").name() << endl;   //输出char const [6]

	//输出指针类型
	int* p = NULL;
	cout << typeid(p).name() << endl;

	//输出表达式类型
	cout << typeid(1.234*456).name() << endl;


	CString  str3;
	const char* msg = "ccc;ALL";
	str3.Format("%s",msg);



}
