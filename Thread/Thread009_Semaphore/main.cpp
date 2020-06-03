//2020.05.29  GM 
//学习信号量的使用方法

#include<Windows.h>
#include<stdio.h>

DWORD WINAPI ThreadFun(LPVOID paramter);

//车辆名称和停车时间
struct Car
{
	char name[20];
	DWORD time;
};

HANDLE hSemaphore = INVALID_HANDLE_VALUE;


int main01()
{
	//只有三个停车位资源
	hSemaphore = CreateSemaphore(NULL, 3, 3, L"停车位");

	HANDLE hArr[5] = { INVALID_HANDLE_VALUE };

	for (int i = 0; i < 5; i++)
	{
		Car* pCar = new Car;
		sprintf_s(pCar->name, "车辆%c", 'A' + i);
		pCar->time = 3 + i * 3;

		//创建车辆线程
		hArr[i]=CreateThread(NULL, 0, ThreadFun, (LPVOID)pCar, 0, NULL);
	}

	//等待所有线程执行完毕
	WaitForMultipleObjects(5, hArr, true, INFINITE);


	return 0;
}


DWORD WINAPI ThreadFun(LPVOID paramter)
{
	//如果停车位资源剩余(有信号状态)，就放行
	WaitForSingleObject(hSemaphore, INFINITE);

	Car* pCar = (Car*)paramter;
	printf("%s进入停车场，停车%d秒！\n", pCar->name, pCar->time);
	Sleep(pCar->time * 1000);
	printf("%s驶离停车场！\n", pCar->name);
	//释放一个停车位（信号量+1）
	ReleaseSemaphore(hSemaphore, 1, NULL);
	return 0;

}
