//ѧϰextern C ���÷�
//2020.06.07 GM 

#include<iostream>
#include"Dll005_extern_C_dll/005.h"
#include<Windows.h>

//��C++��ʹ��C���Եĺ���
#ifdef __cplusplus
extern "C"
{
#endif // _cplusplus

#include"001.h"

#ifdef __cplusplus
}
#endif // _cplusplus

using namespace std;

//extern �ؼ��֣���ʾaaa���������ļ����Ѷ���
extern int aaa;



int main()
{

	cout << aaa << endl;

	HMODULE h = LoadLibrary(L"Dll005_extern_C_dll.dll");
	typedef int(*PSUM)(int, int);
	PSUM psum = (PSUM)GetProcAddress(h, "sum");
	cout << psum(444, 555) << endl;

	FreeLibrary(h);

	//��C++��ʹ��C���Եĺ���
	fun();

	return 0; 
}