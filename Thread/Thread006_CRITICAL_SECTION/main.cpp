//ѧϰ���߳�ģ���վ��Ʊ
//2020/05/05  GM
#include<process.h>
#include<windows.h>
#include<stdio.h>

void _cdecl SellThread1(void* param);
void _cdecl SellThread2(void* param);
//100��Ʊ
int tickets = 100;

//1.�ٽ����ṹ
CRITICAL_SECTION Section;


//����Ŀͨ���ٽ����ķ��������0Ʊ������
int main()
{
	//2.��ʼ���ٽ���
	InitializeCriticalSection(&Section);


	printf("������Ʊ��\n");
	//����������Ʊ����
	uintptr_t t1 = _beginthread(SellThread1, 0, (void*)"��Ʊ����A");
	uintptr_t t2 = _beginthread(SellThread2, 0, (void*)"��Ʊ����B");

	HANDLE hArr[] = { (HANDLE)t1,(HANDLE)t2 };
	WaitForMultipleObjects(2, hArr, true, INFINITE);
	
	printf("��Ʊ����\n");

	//5.ɾ���ٽ���
	DeleteCriticalSection(&Section);

	return 0;
}



void _cdecl SellThread1(void* param)
{
	char* p = (char*)param;



	while (tickets > 0)
	{
		//3.�����ٽ�������ֹ�����̷߳���
		//EnterCriticalSection(&Section);

		//���Խ����ٽ��������������߳�
		if (TryEnterCriticalSection(&Section))
		{
			if (tickets > 0)
			{
				Sleep(10);
				printf("%s������%d��Ʊ��\n", p, tickets--);
			}

			//4.�뿪�ٽ���
			LeaveCriticalSection(&Section);
		}

	}



}

void _cdecl SellThread2(void* param)
{
	char* p = (char*)param;



	while (tickets > 0)
	{
		//3.�����ٽ�������ֹ�����̷߳���
		EnterCriticalSection(&Section);
		if (tickets > 0)
		{
			Sleep(10);
			printf("%s������%d��Ʊ��\n", p, tickets--);
		}
		//4.�����ٽ�������ֹ�����̷߳���
		EnterCriticalSection(&Section);
	}

}

