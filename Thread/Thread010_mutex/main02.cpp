//����mutexʵ�ֳ���Sֻ����һ������
#include<Windows.h>
#include<stdio.h>

int main()
{
	//����������ʵ��һ������ֻ����һ��ʵ�������̣�
	HANDLE hMutex = CreateMutex(NULL, FALSE, L"��Ʊ������");
	if (GetLastError() == ERROR_ALREADY_EXISTS)
	{
		printf("�����Ѿ����У��벻Ҫ�����������");
		getchar();
		//������л������������ͷž��
		CloseHandle(hMutex);
		return 0;
	}

	printf("�����һ������!");
	getchar();
	return 0;
}
