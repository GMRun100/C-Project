//学习线程本地存储 ----静态TLS
//2020.05.31 GM 
#include<windows.h>
#include<stdio.h>

//声明为静态TLS(线程本地存储变量)
_declspec(thread)  int N = 0;  //每个线程中的值互不影响

DWORD WINAPI ThreadFun1(LPVOID param);
DWORD WINAPI ThreadFun2(LPVOID param);
int main01()
{
	HANDLE hThread1 = CreateThread(NULL, 0, ThreadFun1, NULL, 0, NULL);
	HANDLE hThread2 = CreateThread(NULL, 0, ThreadFun2, NULL, 0, NULL);
	HANDLE hArr[] = { hThread1,hThread2 };
	WaitForMultipleObjects(2, hArr, TRUE, INFINITE);
	return 0;
}
DWORD WINAPI ThreadFun1(LPVOID param)
{
	while (TRUE)
	{
		//每个线程中都有自己的N
		printf("线程A打印:%d\n", ++N);
		Sleep(1000);
	}
}

DWORD WINAPI ThreadFun2(LPVOID param)
{
	while (TRUE)
	{
		//每个线程中都有自己的N
		printf("线程B打印:%d\n", N);
		Sleep(1000);
	}
}
