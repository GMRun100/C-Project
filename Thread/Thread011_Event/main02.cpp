//利用event实现程序S只允许一个进程
#include<Windows.h>
#include<stdio.h>

int main()
{
	//创建事件对象实现一个程序只允许一个实例（进程）
	HANDLE hEvent = CreateEvent(NULL, FALSE,TRUE, L"售票互斥体");
	if (GetLastError() == ERROR_ALREADY_EXISTS)
	{
		printf("程序已经运行，请不要开启多个进程");
		getchar();
		//如果已有事件对象存在则释放句柄
		CloseHandle(hEvent);
		return 0;
	}

	printf("程序第一次启动!");
	getchar();
	return 0;
}
