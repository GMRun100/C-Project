//ѧϰstd::future���ʹ��
//2020.06.03 GM

#include<iostream>
#include<future>
using namespace std;
using namespace std::this_thread;
using namespace std::chrono;
//��ʱ�Ĳ���
int add(int a, int b)
{
	cout << "��ʼ����:" << endl;
	sleep_for(seconds(5));//��������ʱ5��
	return a + b;

}

int main()
{
	//�����Ľ��
	future<int> res = async(add, 123, 456);
	res.wait();   //�ȴ��������������Ż����ִ��
	cout << "������:" << endl;
	int sum = res.get();//��ȡ���
	cout << "���յĽ����:" << sum << endl;
	return 0;
}
