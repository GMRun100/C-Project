#include<windows.h>
#include<iostream>
using namespace std;
//线程处理函数，windows标准调用约定_stdcall
DWORD WINAPI ThreadFun02(LPVOID lpThreadParameter);


int main()
{
	cout << "主线程开始" << endl;
	HANDLE hThread1 = CreateThread(NULL,0,ThreadFun02,(LPVOID)"A",0,NULL);
	HANDLE hThread2= CreateThread(NULL, 0, ThreadFun02, (LPVOID)"B", 0, NULL);
	HANDLE hThread3 = CreateThread(NULL, 0, ThreadFun02, (LPVOID)"C", 0, NULL);

	HANDLE handleArr[] = { hThread1,hThread2,hThread3 };

	//场景一：无限等待所有线程结束
	//DWORD ret = WaitForMultipleObjects(3, handleArr, true, INFINITE);
	//cout << "所有线程已结束:" << ret << endl;

	//场景二：等待任意一个线程结束就返回数组索引
	////DWORD ret = WaitForMultipleObjects(3, handleArr, false, INFINITE);
	////cout << "返回的线程是:" << ret << endl;

	//场景三：设置等待超时时间1秒
	DWORD ret= WaitForMultipleObjects(3, handleArr, false, 1000);
	cout << "ret==:" << (ret==WAIT_TIMEOUT) << endl;
	
	cout << "主线程结束" << endl;
	return 0;
}

DWORD WINAPI ThreadFun02(LPVOID lpThreadParameter)
{
	char* str = (char*)lpThreadParameter;
	if (strcmp(str, "A") == 0)
	{
		Sleep(10000);
	}
	else if (strcmp(str, "B") == 0)
	{
		Sleep(3000);
	}
	else
	{
		Sleep(8000);
	}



	cout << str << "子线程结束" << endl;

	return 0;
}