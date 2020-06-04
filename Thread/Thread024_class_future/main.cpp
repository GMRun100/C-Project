//学习std::future类的使用
//2020.06.03 GM

#include<iostream>
#include<future>
using namespace std;
using namespace std::this_thread;
using namespace std::chrono;
//费时的操作
int add(int a, int b)
{
	cout << "开始计算:" << endl;
	sleep_for(seconds(5));//这个计算耗时5秒
	return a + b;

}

int main()
{
	//将来的结果
	future<int> res = async(add, 123, 456);
	res.wait();   //等待结果算出，算出后才会继续执行
	cout << "算出结果:" << endl;
	int sum = res.get();//获取结果
	cout << "最终的结果是:" << sum << endl;
	return 0;
}
