//����Semaphoreʵ�ֳ���Sֻ����һ������
#include<Windows.h>
#include<stdio.h>

int main()
{
	//����Semaphoreʵ�ֳ���Sֻ����һ����������
	HANDLE hSemaphore = CreateSemaphore(NULL, 3, 3, L"sample");
	if (GetLastError() == ERROR_ALREADY_EXISTS)
	{
		printf("�����Ѿ����У��벻Ҫ�����������");
		getchar();
		//������л������������ͷž��
		CloseHandle(hSemaphore);
		return 0;
	}

	printf("�����һ������!");
	getchar();
	return 0;
}
