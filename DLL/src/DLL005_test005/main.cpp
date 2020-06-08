//学习extern C 的用法
//2020.06.07 GM 

#include<iostream>
#include"Dll005_extern_C_dll/005.h"
#include<Windows.h>

//在C++中使用C语言的函数
#ifdef __cplusplus
extern "C"
{
#endif // _cplusplus

#include"001.h"

#ifdef __cplusplus
}
#endif // _cplusplus

using namespace std;

//extern 关键字，表示aaa在其他的文件中已定义
extern int aaa;



int main()
{

	cout << aaa << endl;

	HMODULE h = LoadLibrary(L"Dll005_extern_C_dll.dll");
	typedef int(*PSUM)(int, int);
	PSUM psum = (PSUM)GetProcAddress(h, "sum");
	cout << psum(444, 555) << endl;

	FreeLibrary(h);

	//在C++中使用C语言的函数
	fun();

	return 0; 
}