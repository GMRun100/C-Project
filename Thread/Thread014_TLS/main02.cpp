//ѧϰ�̱߳��ش洢----��̬ TLS
//2020.05.31 GM 
#include<windows.h>
#include<stdio.h>



DWORD WINAPI ThreadFun3(LPVOID param);
DWORD WINAPI ThreadFun4(LPVOID param);

//��̬TLS������
DWORD tlsIndex = 0;

int main()
{
	tlsIndex = TlsAlloc();
	if (tlsIndex == TLS_OUT_OF_INDEXES)
	{
		printf("����TLS����ʧ��!");
		return 0;
	}
	//�����߳�����һ��ֵ
	TlsSetValue(tlsIndex, (LPVOID)"cpp");
	char* p = (char*)TlsGetValue(tlsIndex);
	printf("���̴߳�ӡ:%s\n", p);

	HANDLE hThread1 = CreateThread(NULL, 0, ThreadFun3, NULL, 0, NULL);
	HANDLE hThread2 = CreateThread(NULL, 0, ThreadFun4, NULL, 0, NULL);
	HANDLE hArr[] = { hThread1,hThread2 };
	WaitForMultipleObjects(2, hArr, TRUE, INFINITE);

	//�ͷ�λ��
	TlsFree(tlsIndex);
	return 0;
}
DWORD WINAPI ThreadFun3(LPVOID param)
{
		TlsSetValue(tlsIndex, (LPVOID)"hello");
	
	while (TRUE)
	{
		//ÿ���߳�ͬһ������λ�õ�ֵֻ�����Լ�,�������߳�û��ϵ
		char* p = (char*)TlsGetValue(tlsIndex);
		printf("�߳�A��ӡ:%s\n", p);
		Sleep(1000);
	}
}

DWORD WINAPI ThreadFun4(LPVOID param)
{
	TlsSetValue(tlsIndex, (LPVOID)"world");
	while (TRUE)
	{
		//ÿ���߳��ж����Լ���p
		char* p = (char*)TlsGetValue(tlsIndex);
		printf("�߳�B��ӡ:%s\n", p);
		Sleep(1000);
	}
}
