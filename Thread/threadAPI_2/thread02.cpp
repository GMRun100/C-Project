#include<windows.h>
#include<iostream>
using namespace std;
//�̴߳�������windows��׼����Լ��_stdcall
DWORD WINAPI ThreadFun02(LPVOID lpThreadParameter);


int main()
{
	cout << "���߳̿�ʼ" << endl;
	HANDLE hThread1 = CreateThread(NULL,0,ThreadFun02,(LPVOID)"A",0,NULL);
	HANDLE hThread2= CreateThread(NULL, 0, ThreadFun02, (LPVOID)"B", 0, NULL);
	HANDLE hThread3 = CreateThread(NULL, 0, ThreadFun02, (LPVOID)"C", 0, NULL);

	HANDLE handleArr[] = { hThread1,hThread2,hThread3 };

	//����һ�����޵ȴ������߳̽���
	//DWORD ret = WaitForMultipleObjects(3, handleArr, true, INFINITE);
	//cout << "�����߳��ѽ���:" << ret << endl;

	//���������ȴ�����һ���߳̽����ͷ�����������
	////DWORD ret = WaitForMultipleObjects(3, handleArr, false, INFINITE);
	////cout << "���ص��߳���:" << ret << endl;

	//�����������õȴ���ʱʱ��1��
	DWORD ret= WaitForMultipleObjects(3, handleArr, false, 1000);
	cout << "ret==:" << (ret==WAIT_TIMEOUT) << endl;
	
	cout << "���߳̽���" << endl;
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



	cout << str << "���߳̽���" << endl;

	return 0;
}