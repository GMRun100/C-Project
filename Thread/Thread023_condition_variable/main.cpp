//学习condition_variable条件变量
//2020.06.03 GM

#include<thread>
#include<mutex>
#include<condition_variable>
#include<iostream>
using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

condition_variable cv;//仅支持unique_lock<mutex>作为wait参数
condition_variable_any cv2;//支持接收任何lockable参数作为wait的参数
mutex m;

void ThreadFun(int id)
{
	unique_lock<mutex> lck(m);
	//cv.wait(lck);//等待被唤醒
	cv2.wait(lck);
	cout << "线程ID:" << id << "执行！" << endl;
}

int main()
{
	thread t1(ThreadFun, 1);
	thread t2(ThreadFun, 2);
	thread t3(ThreadFun, 3);

	cout << "3秒后唤醒:" << endl;
	sleep_for(seconds(3));   //3秒之后唤醒所有线程

	//cv.notify_all();  //唤醒所有线程

	//cv.notify_one();   //只唤醒一个线程，被唤醒的线程是随机的
	cv2.notify_all();

	t1.join();
	t2.join();
	t3.join();

	return 0;
}
