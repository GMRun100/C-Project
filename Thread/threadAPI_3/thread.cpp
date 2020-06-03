#include<process.h>
#include<windows.h>
#include<stdio.h>
void ThreadFun(void* param);



int main()
{
	printf("主线程开始！\n");
	//推荐使用C++运行期库函数_beginthread
	HANDLE hThread=(HANDLE)_beginthread(ThreadFun, 0, (void*)"hello");
	WaitForSingleObject(hThread, INFINITE);
	printf("主线程结束！\n");

	return 0;
}

void ThreadFun(void* param)
{
	char* str = (char*)param;
	int n = 0;
	while (++n <= 6)
	{
		printf("第%d次打印%s\n", n, str);
		Sleep(1000);
		if (n == 3)
		{
			//结束__beginthread创建的线程，别用exitthread
			_endthread();
		}
	}

	printf("子线程结束！\n");
}

