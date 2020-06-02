//学习线程本地存储----动态 TLS
//2020.05.31 GM 
#include<windows.h>
#include<stdio.h>



DWORD WINAPI ThreadFun3(LPVOID param);
DWORD WINAPI ThreadFun4(LPVOID param);

//动态TLS的索引
DWORD tlsIndex = 0;

int main()
{
	tlsIndex = TlsAlloc();
	if (tlsIndex == TLS_OUT_OF_INDEXES)
	{
		printf("分配TLS索引失败!");
		return 0;
	}
	//在主线程设置一个值
	TlsSetValue(tlsIndex, (LPVOID)"cpp");
	char* p = (char*)TlsGetValue(tlsIndex);
	printf("主线程打印:%s\n", p);

	HANDLE hThread1 = CreateThread(NULL, 0, ThreadFun3, NULL, 0, NULL);
	HANDLE hThread2 = CreateThread(NULL, 0, ThreadFun4, NULL, 0, NULL);
	HANDLE hArr[] = { hThread1,hThread2 };
	WaitForMultipleObjects(2, hArr, TRUE, INFINITE);

	//释放位置
	TlsFree(tlsIndex);
	return 0;
}
DWORD WINAPI ThreadFun3(LPVOID param)
{
		TlsSetValue(tlsIndex, (LPVOID)"hello");
	
	while (TRUE)
	{
		//每个线程同一个索引位置的值只属于自己,和其他线程没关系
		char* p = (char*)TlsGetValue(tlsIndex);
		printf("线程A打印:%s\n", p);
		Sleep(1000);
	}
}

DWORD WINAPI ThreadFun4(LPVOID param)
{
	TlsSetValue(tlsIndex, (LPVOID)"world");
	while (TRUE)
	{
		//每个线程中都有自己的p
		char* p = (char*)TlsGetValue(tlsIndex);
		printf("线程B打印:%s\n", p);
		Sleep(1000);
	}
}
