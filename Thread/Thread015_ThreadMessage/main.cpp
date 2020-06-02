//学习多线程间消息通讯
//2020.05.31  GM 

#include<Windows.h>
#include<stdio.h>

DWORD WINAPI ThreadFun1(LPVOID param);
DWORD WINAPI ThreadFun2(LPVOID param);

//自定义消息(必须是自定义消息以上的数值)
#define MY_MSG WM_USER+1


int main()
{
	DWORD threadID = 0;

	//获取第一个线程的ID，方便第二个线程给第一个线程发消息
	HANDLE hThread1 = CreateThread(NULL, 0, ThreadFun1, NULL, 0, &threadID);
	HANDLE hThread2 = CreateThread(NULL, 0, ThreadFun2, (LPVOID)threadID, 0, NULL);

	HANDLE hArr[] = { hThread1 ,hThread2 };

	WaitForMultipleObjects(2, hArr, TRUE, INFINITE);

	return 0;
}


DWORD WINAPI ThreadFun1(LPVOID param)
{
	//接收第二个线程发来的消息
	MSG msg;
	//接收消息方式一  使用GetMessage   当没有消息时会阻塞线程
	/*while (GetMessage(&msg, NULL, 0, 0))//如果有消息，继续，否则阻塞
	{
		//判断消息
		switch (msg.message)
		{
		case MY_MSG:
			printf("收到消息:%d\n", (int)msg.wParam);
		default:
			break;
		}		
	}*/


	//接收消息方式二   使用PeekMessage   当没有消息时会立即返回
	while (TRUE)
	{
		//马上就返回，不阻塞线程
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			//判断消息
			switch (msg.message)
			{
			case MY_MSG:
				printf("收到消息:%d\n", (int)msg.wParam);
				break;
			case WM_QUIT:
				printf("收到WM_QUIT消息,退出\n");
				return 0;
				break;
			}
		}

	}





	return 0;
}


DWORD WINAPI ThreadFun2(LPVOID param)
{
	//给第一个线程发消息
	DWORD pthreadId = (DWORD)param;
	int N = 1;
	while (TRUE)
	{
		if (N <= 10)
		{
			PostThreadMessage(pthreadId, MY_MSG, (WPARAM)N++, NULL);
		}
		else
		{
			//让第一个线程退出
			PostThreadMessage(pthreadId, WM_QUIT,NULL, NULL);
			break;
		}

		Sleep(1000);
	}
	return 0;
}