//示例：十个线程赛跑挣第一

#include<atomic>
#include<thread>
#include<vector>
#include<iostream>
using namespace std;
using namespace std::this_thread;
atomic<bool> ready=false;   //是否枪响

atomic_flag win = ATOMIC_FLAG_INIT;//重点线

void Run(int id);

int main()
{
	//十个选手赛跑
	vector<thread> vecPlayers;
	for (int i = 1; i <= 10; i++)
	{
		vecPlayers.push_back(thread(Run, i));
	}
	cout << "10个选手已经准备好！" << endl;

	//准备发命令:预备跑
	sleep_for(chrono::seconds(3));
	cout << "3 2 1 预备跑！" << endl;

	ready = true;  //可以跑了

	//等待所有选手跑完
	for (thread& t : vecPlayers)
	{
		t.join(); 
	}
}


void Run(int id)
{
	//抢没响，不能跑
	while (!ready)
	{
		yield();  //让其他线程先执行
	}

	//表示跑的过程
	for (int i = 0; i < 100000; i++)
	{
	}

	//如果没有被设置过，返回false
	if (!win.test_and_set())//调用后会将它设置
	{
		cout << id << "号选手赢得第一名" << endl;
	}
}