//ѧϰC++11 thread��
//2020.06.01 GM 

#include<iostream>
#include<thread>

using namespace std;

void ThreadFun(string str);


int main()
{
	//Ĭ�Ϲ��캯��
	thread t1;
	cout << t1.get_id() << endl;//Ϊ0
	cout << t1.joinable() << endl;    //Ϊ0,��ʾ����join


	//ʹ�ô������Ĺ��캯��
	thread t2(ThreadFun,"hello");
	cout << t2.get_id() << endl;
	cout << t2.joinable() << endl;
	//thread����������֮ǰ�������join,���������ֹ������detach
	//�߳����ٷ�ʽһ������join
	t2.join();  //�ȴ����߳�ִ�����,������waitforsignleobject����

	//�߳����ٷ�ʽ��������detach
	//t2.detach();  //�뵱ǰ�̶߳�����룬��Ϊ�¶��߳�

	return 0;
}


void ThreadFun(string str)
{
	cout << str.c_str() << endl;
}

