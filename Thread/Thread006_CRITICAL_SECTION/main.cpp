//学习多线程模拟火车站售票
//2020/05/05  GM
#include<process.h>
#include<windows.h>
#include<stdio.h>

void _cdecl SellThread1(void* param);
void _cdecl SellThread2(void* param);
//100张票
int tickets = 100;

//1.临界区结构
CRITICAL_SECTION Section;


//本项目通过临界区的方法解决卖0票的问题
int main()
{
	//2.初始化临界区
	InitializeCriticalSection(&Section);


	printf("开售买票了\n");
	//创建两个售票窗口
	uintptr_t t1 = _beginthread(SellThread1, 0, (void*)"售票窗口A");
	uintptr_t t2 = _beginthread(SellThread2, 0, (void*)"售票窗口B");

	HANDLE hArr[] = { (HANDLE)t1,(HANDLE)t2 };
	WaitForMultipleObjects(2, hArr, true, INFINITE);
	
	printf("买票结束\n");

	//5.删除临界区
	DeleteCriticalSection(&Section);

	return 0;
}



void _cdecl SellThread1(void* param)
{
	char* p = (char*)param;



	while (tickets > 0)
	{
		//3.进入临界区，禁止其他线程访问
		//EnterCriticalSection(&Section);

		//尝试进入临界区，不会阻塞线程
		if (TryEnterCriticalSection(&Section))
		{
			if (tickets > 0)
			{
				Sleep(10);
				printf("%s卖出第%d张票！\n", p, tickets--);
			}

			//4.离开临界区
			LeaveCriticalSection(&Section);
		}

	}



}

void _cdecl SellThread2(void* param)
{
	char* p = (char*)param;



	while (tickets > 0)
	{
		//3.进入临界区，禁止其他线程访问
		EnterCriticalSection(&Section);
		if (tickets > 0)
		{
			Sleep(10);
			printf("%s卖出第%d张票！\n", p, tickets--);
		}
		//4.进入临界区，禁止其他线程访问
		EnterCriticalSection(&Section);
	}

}

