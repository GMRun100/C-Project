//ѧϰpackaged_task��
//2020.06.03 GM

#include<iostream>
#include<future>
#include<thread>
using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

int work(int a, int b)
{
	//�����ʱ����
	cout << "��ʼ����:" << endl;
	sleep_for(seconds(5));
	cout << "�������:" << endl;
	return a + b;
}

int main()
{
	//packaged_task��װ��һ���ɵ��õ�Ŀ��
	packaged_task<int(int, int)> pack(work);

	future<int> res = pack.get_future();//��ȡpackaged_task�ڲ���future

	thread t1(move(pack),123,456);   //��packaged_task���߳�ִ��

	t1.detach();

	int sum = res.get();
	cout << "���յĽ����:" << sum << endl;




	return 0;
}
