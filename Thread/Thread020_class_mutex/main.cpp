//ѧϰmutex��
//2020.06.02 GM 
#include<iostream>
#include<thread>
#include<stdio.h>
#include<mutex>
using namespace std;
using namespace std::this_thread;
using namespace std::chrono;
int tickets = 100;

mutex m;				//����һ��mutex����
recursive_mutex m2;		//���Եݹ����
timed_mutex m3;			//����ָ����ס��ʱ��

void SellThread(string str)
{
	while (tickets > 0)
	{
		//������ʽһ
		//m.lock();  //����

		//������ʽ��  ���Եݹ����
		//m2.lock();
		//m2.lock();  //���Եݹ����

		//������ʽ��
		m3.try_lock_for(seconds(3));
		if (tickets > 0)
		{
			
			sleep_for(milliseconds(100));
			printf("%s ����%dƱ\n",str.c_str(), tickets--);
		}
		//m.unlock(); //����
		//m2.unlock();
		//m2.unlock();//�Ӽ�������Ҫ�⼸����
		//sleep_for(milliseconds(100));
	}
}


int main()
{
	thread t1(SellThread,"��Ʊ����A:");
	thread t2(SellThread, "��Ʊ����B:");

	t1.join();
	t2.join();

	return 0;
}