//学习调用dll的第二种方式
//2020.6.6 GM 
#include<iostream>
#include<Windows.h>
using namespace std;


int main()
{
	//调用dll的第二种方式：win32 API+.dll
	//1.加载dll
	HMODULE h = LoadLibrary(L"DLL004_dll.dll");

	//2.获取函数地址
	typedef int(*PSUM)(int, int);   //定义一个函数指针类型
	//3.利用函数指针调用函数
	//PSUM psum=(PSUM)GetProcAddress(h, "sum");   //方式一  写函数名
	PSUM psum = (PSUM)GetProcAddress(h,(char *)1);   //方式二  利用序号获取函数地址  可通过Dependency Walker工具查看函数序号

	cout << psum(333,444) << endl;

	//4.释放dll
	FreeLibrary(h);
	return 0;
}