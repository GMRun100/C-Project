//学习packaged_task类
//2020.06.03 GM

#include<iostream>
#include<future>
#include<thread>
using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

int work(int a, int b)
{
	//处理费时操作
	cout << "开始计算:" << endl;
	sleep_for(seconds(5));
	cout << "计算完成:" << endl;
	return a + b;
}

int main()
{
	//packaged_task包装了一个可调用的目标
	packaged_task<int(int, int)> pack(work);

	future<int> res = pack.get_future();//获取packaged_task内部的future

	thread t1(move(pack),123,456);   //将packaged_task给线程执行

	t1.detach();

	int sum = res.get();
	cout << "最终的结果是:" << sum << endl;




	return 0;
}
