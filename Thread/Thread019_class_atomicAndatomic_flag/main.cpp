//ѧϰatomic���atomic_flag��
//2020.6.2 GM 
#include<iostream>
#include<atomic>   //ԭ�Ӳ���ͷ�ļ�
#include<thread>
using namespace std;

atomic<int> N = 0;  //��atomic��֤��N�Ĳ�����ԭ����

void ThreadFun()
{
	for (int i = 0; i < 10000000; i++)
	{
		++N;
	}
}

int main01()
{
	//ÿ���߳�100��+1
	thread t1(ThreadFun);
	thread t2(ThreadFun);

	t1.join();
	t2.join();

	cout << N << endl;   //�̲߳������¼Ӳ����ص�������ԭ�Ӳ�������˿϶�����20000000
	return 0;
}
