//学习mutex类
//2020.06.02 GM 
#include<iostream>
#include<thread>
#include<stdio.h>
#include<mutex>
using namespace std;
using namespace std::this_thread;
using namespace std::chrono;
int tickets = 100;

mutex m;				//定义一个mutex对象
recursive_mutex m2;		//可以递归加锁
timed_mutex m3;			//可以指定锁住的时间

void SellThread(string str)
{
	while (tickets > 0)
	{
		//加锁方式一
		//m.lock();  //加锁

		//加锁方式二  可以递归加锁
		//m2.lock();
		//m2.lock();  //可以递归加锁

		//加锁方式三
		m3.try_lock_for(seconds(3));
		if (tickets > 0)
		{
			
			sleep_for(milliseconds(100));
			printf("%s 卖出%d票\n",str.c_str(), tickets--);
		}
		//m.unlock(); //解锁
		//m2.unlock();
		//m2.unlock();//加几次锁就要解几次锁
		//sleep_for(milliseconds(100));
	}
}


int main()
{
	thread t1(SellThread,"售票窗口A:");
	thread t2(SellThread, "售票窗口B:");

	t1.join();
	t2.join();

	return 0;
}