//学习锁管理lock_guard类
//2020.6.2 GM

#include<iostream>
#include<mutex>
#include<thread>
#include<stdexcept>
using namespace std;
using namespace this_thread;
mutex m;
void ThreadFun()
{
	try
	{
		for (int i = 0; i < 10; ++i)
		{
			//m.lock();
			sleep_for(chrono::seconds(1));
			lock_guard<mutex> lck(m);	//哪怕发生异常也是可以安全解锁，因为lck会析构，然后解锁mutex
			if (i == 3) throw logic_error("发生异常了");

			cout << "A打印" << i << endl;			
			//m.unlock();  //抛出异常时，导致没有unlock,使得B无法获取mutex,死锁
		}
	}
	catch (logic_error& e)
	{
		cout << "错误" << e.what() << endl;
	}

}


void ThreadFun2()
{

		for (int i = 0; i < 10; ++i)
		{
			sleep_for(chrono::seconds(1));
			lock_guard<mutex> lck(m);
			//m.lock();
			cout << "B打印" << i << endl;
			//m.unlock();
		}


}
int main()
{
	thread t1(ThreadFun);
	thread t2(ThreadFun2);
	return 0;
}
