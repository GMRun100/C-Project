//ѧϰ���߳�ģ���վ��Ʊ
//2020/05/05  GM
#include<process.h>
#include<windows.h>
#include<stdio.h>

void _cdecl SellThread1(void* param);
void _cdecl SellThread2(void* param);
//100��Ʊ
int tickets = 100;

//�������0Ʊ������
int main()
{
	printf("������Ʊ��\n");
	//����������Ʊ����
	uintptr_t t1 = _beginthread(SellThread1, 0,(void *) "��Ʊ����A");
	uintptr_t t2 = _beginthread(SellThread2, 0, (void*)"��Ʊ����B");

	HANDLE hArr[] = { (HANDLE)t1,(HANDLE)t2 };
	WaitForMultipleObjects(2, hArr, true, INFINITE);

	printf("��Ʊ����\n");

	return 0;
}



void _cdecl SellThread1(void* param)
{
	char* p = (char*)param;
	while (tickets>0)
	{
		Sleep(10);
		printf("%s������%d��Ʊ��\n",p, tickets--);
	}

}

void _cdecl SellThread2(void* param)
{
	char* p = (char*)param;
	while (tickets > 0)
	{
		Sleep(10);
		printf("%s������%d��Ʊ��\n",p, tickets--);
	}
}

