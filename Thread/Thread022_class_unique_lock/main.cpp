//ѧϰ������unique_lock��
//2020.6.3 GM

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
			
			unique_lock<mutex> lck(m);	//���·����쳣Ҳ�ǿ��԰�ȫ��������Ϊlck��������Ȼ�����mutex
			if (i == 3) throw logic_error("�����쳣��");

			cout << "A��ӡ" << i << endl;
			//m.unlock();  //�׳��쳣ʱ������û��unlock,ʹ��B�޷���ȡmutex,����
			lck.unlock();//�����������ƽ�������unique_lock�����
			sleep_for(chrono::seconds(1));
		}
	}
	catch (logic_error& e)
	{
		cout << "����" << e.what() << endl;
	}

}


void ThreadFun2()
{

	for (int i = 0; i < 10; ++i)
	{
		
		unique_lock<mutex> lck(m);
		//m.lock();
		cout << "B��ӡ" << i << endl;
		//m.unlock();
		lck.unlock();
		sleep_for(chrono::seconds(1));
	}


}
int main()
{
	thread t1(ThreadFun);
	thread t2(ThreadFun2);
	return 0;
}