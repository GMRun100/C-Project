#include<process.h>
#include<windows.h>
#include<stdio.h>
void ThreadFun(void* param);



int main()
{
	printf("���߳̿�ʼ��\n");
	//�Ƽ�ʹ��C++�����ڿ⺯��_beginthread
	HANDLE hThread=(HANDLE)_beginthread(ThreadFun, 0, (void*)"hello");
	WaitForSingleObject(hThread, INFINITE);
	printf("���߳̽�����\n");

	return 0;
}

void ThreadFun(void* param)
{
	char* str = (char*)param;
	int n = 0;
	while (++n <= 6)
	{
		printf("��%d�δ�ӡ%s\n", n, str);
		Sleep(1000);
		if (n == 3)
		{
			//����__beginthread�������̣߳�����exitthread
			_endthread();
		}
	}

	printf("���߳̽�����\n");
}

