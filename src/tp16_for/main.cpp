//ѧϰ������forѭ��
//2019.10.26 GM

#include<iostream>
using namespace std;

template<int N>
struct For
{
	static void F()
	{
		cout << "ѭ����ִ�����" << N << endl;
		For<N - 1>::F();
	}
};


//����ȫ�ػ�����ֹ�ݹ�
template<>
struct For<0>
{
	static void F()
	{
		cout << "ѭ����ִ�����" << 0 << endl;
	}
};


void main()
{
	For<5>::F();
}