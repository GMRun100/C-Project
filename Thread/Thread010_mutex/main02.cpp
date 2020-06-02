//利用mutex实现程序S只允许一个进程
#include<Windows.h>
#include<stdio.h>

int main()
{
	//创建互斥体实现一个程序只允许一个实例（进程）
	HANDLE hMutex = CreateMutex(NULL, FALSE, L"售票互斥体");
	if (GetLastError() == ERROR_ALREADY_EXISTS)
	{
		printf("程序已经运行，请不要开启多个进程");
		getchar();
		//如果已有互斥量存在则释放句柄
		CloseHandle(hMutex);
		return 0;
	}

	printf("程序第一次启动!");
	getchar();
	return 0;
}
