//利用Semaphore实现程序S只允许一个进程
#include<Windows.h>
#include<stdio.h>

int main()
{
	//利用Semaphore实现程序S只允许一个进程运行
	HANDLE hSemaphore = CreateSemaphore(NULL, 3, 3, L"sample");
	if (GetLastError() == ERROR_ALREADY_EXISTS)
	{
		printf("程序已经运行，请不要开启多个进程");
		getchar();
		//如果已有互斥量存在则释放句柄
		CloseHandle(hSemaphore);
		return 0;
	}

	printf("程序第一次启动!");
	getchar();
	return 0;
}
