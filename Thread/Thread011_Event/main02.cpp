//����eventʵ�ֳ���Sֻ����һ������
#include<Windows.h>
#include<stdio.h>

int main()
{
	//�����¼�����ʵ��һ������ֻ����һ��ʵ�������̣�
	HANDLE hEvent = CreateEvent(NULL, FALSE,TRUE, L"��Ʊ������");
	if (GetLastError() == ERROR_ALREADY_EXISTS)
	{
		printf("�����Ѿ����У��벻Ҫ�����������");
		getchar();
		//��������¼�����������ͷž��
		CloseHandle(hEvent);
		return 0;
	}

	printf("�����һ������!");
	getchar();
	return 0;
}
