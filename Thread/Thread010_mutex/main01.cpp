//学习多线程同步之mutex
//2020.05.30 GM 

#include<process.h>
#include<windows.h>
#include<stdio.h>

void _cdecl SellThread1(void* param);
void _cdecl SellThread2(void* param);
//100张票
int tickets = 100;

HANDLE hMutex = INVALID_HANDLE_VALUE;

//本项目通过临界区的方法解决卖0票的问题
int main01()
{

	//1.创建互斥体
	hMutex = CreateMutex(NULL, FALSE, L"售票互斥体");


	printf("开售买票了\n");
	//创建两个售票窗口
	uintptr_t t1 = _beginthread(SellThread1, 0, (void*)"售票窗口A");
	uintptr_t t2 = _beginthread(SellThread2, 0, (void*)"售票窗口B");

	HANDLE hArr[] = { (HANDLE)t1,(HANDLE)t2 };
	WaitForMultipleObjects(2, hArr, true, INFINITE);

	printf("买票结束\n");



	return 0;
}



void _cdecl SellThread1(void* param)
{
	char* p = (char*)param;



	while (tickets > 0)
	{
		//如果这个互斥体为有信号状态(没有线程拥有它)，则获取他后继续执行
		WaitForSingleObject(hMutex, INFINITE);
			if (tickets > 0)
			{
				Sleep(10);
				printf("%s卖出第%d张票！\n", p, tickets--);
			}
			//释放对互斥体的拥有权，它变成有信号状态
			ReleaseMutex(hMutex);


	}



}

void _cdecl SellThread2(void* param)
{
	char* p = (char*)param;



	while (tickets > 0)
	{
		//如果这个互斥体为有信号状态(没有线程拥有它)，则获取他后继续执行
		WaitForSingleObject(hMutex, INFINITE);
		if (tickets > 0)
		{
			Sleep(10);
			printf("%s卖出第%d张票！\n", p, tickets--);
		}
		//释放对互斥体的拥有权，它变成有信号状态
		ReleaseMutex(hMutex);
	}

}

