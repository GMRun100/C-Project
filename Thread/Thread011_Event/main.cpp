//学习多线程同步之Event
//2020.05.30 GM 

#include<process.h>
#include<windows.h>
#include<stdio.h>

void _cdecl SellThread1(void* param);
void _cdecl SellThread2(void* param);
//100张票
int tickets = 100;

HANDLE hEvent = INVALID_HANDLE_VALUE;

//本项目通过临界区的方法解决卖0票的问题
int main01()
{
	//1.创建事件，此刻为有信号状态
	//自动重置信号状态，初始化为有信号状态，线程可以直接获取
	hEvent = CreateEvent(NULL, FALSE,true,L"事件对象");

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
		//如果事件对象为有信号状态(没有线程拥有它)，则获取他后继续执行
		//自动重置的事件对象，调用了WaitForSingleObject函数之后，自动重置为无信号
		WaitForSingleObject(hEvent, INFINITE);
		if (tickets > 0)
		{
			Sleep(10);
			printf("%s卖出第%d张票！\n", p, tickets--);
		}
		//让信号状态变成有信号状态
		SetEvent(hEvent);
	}                                                                                                           
}

void _cdecl SellThread2(void* param)
{
	char* p = (char*)param;



	while (tickets > 0)
	{
		//如果事件对象为有信号状态(没有线程拥有它)，则获取他后继续执行
		//自动重置的事件对象，调用了WaitForSingleObject函数之后，自动重置为无信号
		WaitForSingleObject(hEvent, INFINITE);
		if (tickets > 0)
		{
			Sleep(10);
			printf("%s卖出第%d张票！\n", p, tickets--);
		}
		//让信号状态变成有信号状态
		SetEvent(hEvent);
	}

}

