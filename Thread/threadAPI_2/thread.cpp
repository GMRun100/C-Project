#include<windows.h>
#include<iostream>
using namespace std;
//�̴߳�������windows��׼����Լ��_stdcall
DWORD WINAPI ThreadFun(LPVOID lpThreadParameter);


//�������ܣ��ȴ��߳� ��ֹ�߳� 
int main01()
{
	cout << "���߳̿�ͷ" << endl;
	DWORD threadId = 0;
	HANDLE hThread = CreateThread(NULL,//��ΪNULLʹ��Ĭ�ϰ�ȫ��
		0,//���Ϊ0����ôĬ�Ͻ�ʹ������øú������߳���ͬ��ջ�ռ��С
		ThreadFun,//�̴߳����������������Ǻ���ָ��
		(LPVOID)"hello",
		0,//��������������
		&threadId
	);

	DWORD code;
	GetExitCodeThread(hThread, &code);

	if (code == STILL_ACTIVE)
	{
		cout << "���߳�û���˳�" << endl;
	}


	//�ȴ�2S����ʱ�᷵��
	DWORD ret=WaitForSingleObject(hThread,2000);
	if(ret==WAIT_TIMEOUT)
	{
		cout << "�ȴ���ʱ��" << endl;
	}

	//ǿ����ֹ�̣߳�����ʹ��
	TerminateThread(hThread, 888);

	//���޵ȴ����������߳����н���
	WaitForSingleObject(hThread, INFINITE);

	GetExitCodeThread(hThread, &code);
	cout << "���̴߳����룺" << code << endl;


	cout << "���߳̽�β" << endl;

	return 0;
}

DWORD WINAPI ThreadFun(LPVOID lpThreadParameter)
{
	char* str = (char*)lpThreadParameter;
	int n = 6;
	while (--n>0)
	{
		cout << "���߳�"<<n<<"hello!" << endl;
		Sleep(1000);    //1000ms

		//if (n == 3)
		//{
		//	//�˳��̣߳��˳���Ϊ666   
		//	ExitThread(666);    //����ʹ��
		//}

	}

	return 0;
}