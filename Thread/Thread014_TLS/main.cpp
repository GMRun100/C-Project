//ѧϰ�̱߳��ش洢 ----��̬TLS
//2020.05.31 GM 
#include<windows.h>
#include<stdio.h>

//����Ϊ��̬TLS(�̱߳��ش洢����)
_declspec(thread)  int N = 0;  //ÿ���߳��е�ֵ����Ӱ��

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
		//ÿ���߳��ж����Լ���N
		printf("�߳�A��ӡ:%d\n", ++N);
		Sleep(1000);
	}
}

DWORD WINAPI ThreadFun2(LPVOID param)
{
	while (TRUE)
	{
		//ÿ���߳��ж����Լ���N
		printf("�߳�B��ӡ:%d\n", N);
		Sleep(1000);
	}
}
