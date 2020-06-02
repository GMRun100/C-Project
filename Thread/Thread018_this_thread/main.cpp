//学习this_thread命名空间中相关函数的用法
//2020.06.01 GM
#include<iostream>
#include<thread>
using namespace std;
//命名空间this_thread有所有的线程辅助函数 get_id()	yield()  sleep_for()  sleep_util()
using namespace std::this_thread;

//命名空间chrono有seconds模板类 microseconds模板类
using namespace std::chrono;
void ThreadFun(string str);

int main()
{
	thread t1(ThreadFun, string("hello"));
	cout << t1.get_id()<<endl;

	//等待子线程完成
	t1.join();
	return 0;
}

void ThreadFun(string str)
{
	cout << get_id() << endl;   //获取线程id
	while (true)
	{
		cout << str.c_str() << endl;
		//sleep_for(seconds(1));   //让线程睡眠1秒
		yield();  //让线程睡眠一个极小的时间片给其他线程

		sleep_until(system_clock::now() + milliseconds(1000));//让线程睡眠当前时间+1秒

	}
}
