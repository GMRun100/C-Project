//ѧϰ�����ռ�
//2019.09.14 GM 
#include<iostream>
using namespace std;

int a = 10;
namespace A
{
	int a = 100;
	int b = 200;
	//�����ռ����Ƕ��
	namespace B
	{
		int a = 101;
		int b = 201;
		int m = 300;
	}
	namespace
	{
		int z = 1000;
	}
}

int main()
{
	cout << a << endl;
	cout << A::a << endl;
	cout << A::B::b << endl;

	//����ʹ��B�����ռ�
	using namespace A::B;
	cout << b << endl;    //������ʽ��ָ�������ռ�
	cout << m << endl;

	//ʹ�����������ռ��еı���
	cout << A::z << endl;

	return 0;
}