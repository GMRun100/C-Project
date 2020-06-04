#include<iostream>
#include<future>
#include<thread>
using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

//��ʱ����
void work(promise<int> &prom) 
{
	cout << "��ʼ����:" << endl;
	sleep_for(seconds(5));
	//promise���ý��ֵ
	cout << "�������:" << endl;

	//ʹ�ó���һ ����ֵ
	//prom.set_value(666); //���ý����future��get��

	//ʹ�ó����� �����쳣
	try
	{
		throw runtime_error("����ʱ����");
	}
	catch(...)
	{
		//promise�����쳣
		prom.set_exception(current_exception());
	}
}
int main()
{
	//����һ��promise
	promise<int> prom;
	//future��promise����ʹ�ã�������aynsc
	future<int> res = prom.get_future();

	thread t1(work, ref(prom));
	t1.detach();
	try
	{
		int sum = res.get();
		cout << "���յĽ����:" << sum << endl;
	}
	catch(exception &e)
	{
		cout << "����쳣:" << e.what() << endl;
	}


	return 0;
}