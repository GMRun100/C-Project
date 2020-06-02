//学习atomic类和atomic_flag类
//2020.6.2 GM 
#include<iostream>
#include<atomic>   //原子操作头文件
#include<thread>
using namespace std;

atomic<int> N = 0;  //用atomic保证对N的操作的原子性

void ThreadFun()
{
	for (int i = 0; i < 10000000; i++)
	{
		++N;
	}
}

int main01()
{
	//每个线程100次+1
	thread t1(ThreadFun);
	thread t2(ThreadFun);

	t1.join();
	t2.join();

	cout << N << endl;   //线程并发导致加操作重叠，不是原子操作，因此肯定少于20000000
	return 0;
}
