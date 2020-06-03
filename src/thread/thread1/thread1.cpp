#include<Windows.h>
#include<iostream>
using namespace std;
//线程处理函数，windows标准调用约定_stdcall
DWORD WINAPI ThreadFun(LPVOID lpThreadParameter);

int main()
{
	DWORD threadId = 0;
	HANDLE hThread = CreateThread(NULL,//设为NULL使用默认安全性
		0,//如果为0，那么默认将使用与调用该函数的线程相同的栈空间大小
		ThreadFun,//线程处理函数，函数名就是函数指针
		(LPVOID)"hello",
		0,//创建后马上运行
		&threadId
	);

	if (hThread == NULL)
	{
		cout << "线程创建失败" << GetLastError() << endl;
	}

	cout << "线程的句柄:" << hThread << endl;
	cout << "线程的ID:" << threadId << endl;


	cout << "主线程ID:" << GetCurrentThreadId() << endl;


	//关闭线程句柄,引用计数-1，并没有结束线程
	//CloseHandle(hThread);   //表示以后不再引用句柄

	getchar();

	//挂起线程
	SuspendThread(hThread);

	getchar();

	//恢复线程执行
	ResumeThread(hThread);

	getchar();
	
}

DWORD WINAPI ThreadFun(LPVOID lpThreadParameter)
{
	char* str = (char*)lpThreadParameter;

	while (TRUE)
	{
		cout << "线程处理函数中:" << str << endl;
		cout << "子线程ID:" << GetCurrentThreadId() << endl;
		Sleep(1000);    //1000ms
	}



	return 0;
}