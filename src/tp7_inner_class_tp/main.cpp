//ѧϰ�ڲ���ģ��
//2019.10.22 GM
#include<iostream>
using namespace std;
//�ⲿ��
template<typename T>
class Outer
{
public:
	//�ڲ���
	template<typename T2>
	class Inner
	{
	public:
		T2 i;
		void print();
	};

	T o;
	void print();
};

template<typename T>
void Outer<T>::print()
{
	cout << "Outer print" << endl;
}

//֪ʶ������,��Ҫ����ģ������
template<typename T>
template<typename T2>
void Outer<T>::Inner<T2>::print()
{
	cout << "Inner print" << endl;
}
void main()
{
	//�ⲿ�����
	Outer<int> o;
	o.print();

	//�ڲ������������������޶���
	Outer<int>::Inner<int> i;
	i.print();
}