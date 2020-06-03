#include<windows.h>
#include<iostream>
using namespace std;
//线程处理函数，windows标准调用约定_stdcall
DWORD WINAPI ThreadFun(LPVOID lpThreadParameter);


//函数功能：等待线程 终止线程 
int main01()
{
	cout << "主线程开头" << endl;
	DWORD threadId = 0;
	HANDLE hThread = CreateThread(NULL,//设为NULL使用默认安全性
		0,//如果为0，那么默认将使用与调用该函数的线程相同的栈空间大小
		ThreadFun,//线程处理函数，函数名就是函数指针
		(LPVOID)"hello",
		0,//创建后马上运行
		&threadId
	);

	DWORD code;
	GetExitCodeThread(hThread, &code);

	if (code == STILL_ACTIVE)
	{
		cout << "子线程没有退出" << endl;
	}


	//等待2S，超时会返回
	DWORD ret=WaitForSingleObject(hThread,2000);
	if(ret==WAIT_TIMEOUT)
	{
		cout << "等待超时！" << endl;
	}

	//强制终止线程，避免使用
	TerminateThread(hThread, 888);

	//无限等待，除非子线程运行结束
	WaitForSingleObject(hThread, INFINITE);

	GetExitCodeThread(hThread, &code);
	cout << "子线程错误码：" << code << endl;


	cout << "主线程结尾" << endl;

	return 0;
}

DWORD WINAPI ThreadFun(LPVOID lpThreadParameter)
{
	char* str = (char*)lpThreadParameter;
	int n = 6;
	while (--n>0)
	{
		cout << "子线程"<<n<<"hello!" << endl;
		Sleep(1000);    //1000ms

		//if (n == 3)
		//{
		//	//退出线程，退出码为666   
		//	ExitThread(666);    //避免使用
		//}

	}

	return 0;
}