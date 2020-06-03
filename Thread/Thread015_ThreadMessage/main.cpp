//ѧϰ���̼߳���ϢͨѶ
//2020.05.31  GM 

#include<Windows.h>
#include<stdio.h>

DWORD WINAPI ThreadFun1(LPVOID param);
DWORD WINAPI ThreadFun2(LPVOID param);

//�Զ�����Ϣ(�������Զ�����Ϣ���ϵ���ֵ)
#define MY_MSG WM_USER+1


int main()
{
	DWORD threadID = 0;

	//��ȡ��һ���̵߳�ID������ڶ����̸߳���һ���̷߳���Ϣ
	HANDLE hThread1 = CreateThread(NULL, 0, ThreadFun1, NULL, 0, &threadID);
	HANDLE hThread2 = CreateThread(NULL, 0, ThreadFun2, (LPVOID)threadID, 0, NULL);

	HANDLE hArr[] = { hThread1 ,hThread2 };

	WaitForMultipleObjects(2, hArr, TRUE, INFINITE);

	return 0;
}


DWORD WINAPI ThreadFun1(LPVOID param)
{
	//���յڶ����̷߳�������Ϣ
	MSG msg;
	//������Ϣ��ʽһ  ʹ��GetMessage   ��û����Ϣʱ�������߳�
	/*while (GetMessage(&msg, NULL, 0, 0))//�������Ϣ����������������
	{
		//�ж���Ϣ
		switch (msg.message)
		{
		case MY_MSG:
			printf("�յ���Ϣ:%d\n", (int)msg.wParam);
		default:
			break;
		}		
	}*/


	//������Ϣ��ʽ��   ʹ��PeekMessage   ��û����Ϣʱ����������
	while (TRUE)
	{
		//���Ͼͷ��أ��������߳�
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			//�ж���Ϣ
			switch (msg.message)
			{
			case MY_MSG:
				printf("�յ���Ϣ:%d\n", (int)msg.wParam);
				break;
			case WM_QUIT:
				printf("�յ�WM_QUIT��Ϣ,�˳�\n");
				return 0;
				break;
			}
		}

	}





	return 0;
}


DWORD WINAPI ThreadFun2(LPVOID param)
{
	//����һ���̷߳���Ϣ
	DWORD pthreadId = (DWORD)param;
	int N = 1;
	while (TRUE)
	{
		if (N <= 10)
		{
			PostThreadMessage(pthreadId, MY_MSG, (WPARAM)N++, NULL);
		}
		else
		{
			//�õ�һ���߳��˳�
			PostThreadMessage(pthreadId, WM_QUIT,NULL, NULL);
			break;
		}

		Sleep(1000);
	}
	return 0;
}