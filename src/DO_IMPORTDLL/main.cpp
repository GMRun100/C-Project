#include<stdio.h>
#include<iostream>
#include"testdLL.h"

#include<stdafx.h>
#include<Windows.h>  //ͨ������windowsAPI�����غ�ж��DLL
using namespace std;
//��ʽ����DLL
#pragma comment(lib,"G:\\02.Learning\\C++study\\Debug\\DO_DLL.lib")

extern int Add(int plus1, int plus2);

//���庯��ָ��
typedef double(*Dll2fun)(int, int);

void main(void)
{
	//��ʽ����DLL
	int a = 1;
	int b = 2;
	int c = 0;
	c=Add(a, b);
	cout << "c=" << c << endl;

	//��ʾ����DLL
	Dll2fun funName;
	HINSTANCE hdll;
	hdll = LoadLibrary("do_Dll2.dll");
	if (hdll == NULL)
	{
		FreeLibrary(hdll);
	}
	funName = (Dll2fun)GetProcAddress(hdll, "seekArea");
	if (funName == NULL)
	{
		FreeLibrary(hdll);
	}
	int r = 1, h = 10;
	double area = funName(r, h);
	printf("area = %f\n", area);

	FreeLibrary(hdll);



	getchar();

}