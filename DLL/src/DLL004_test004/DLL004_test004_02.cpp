//ѧϰ����dll�ĵڶ��ַ�ʽ
//2020.6.6 GM 
#include<iostream>
#include<Windows.h>
using namespace std;


int main()
{
	//����dll�ĵڶ��ַ�ʽ��win32 API+.dll
	//1.����dll
	HMODULE h = LoadLibrary(L"DLL004_dll.dll");

	//2.��ȡ������ַ
	typedef int(*PSUM)(int, int);   //����һ������ָ������
	//3.���ú���ָ����ú���
	//PSUM psum=(PSUM)GetProcAddress(h, "sum");   //��ʽһ  д������
	PSUM psum = (PSUM)GetProcAddress(h,(char *)1);   //��ʽ��  ������Ż�ȡ������ַ  ��ͨ��Dependency Walker���߲鿴�������

	cout << psum(333,444) << endl;

	//4.�ͷ�dll
	FreeLibrary(h);
	return 0;
}