//ѧϰģ��ľ�̬��Ա
//2019.10.22 GM

#include<iostream>
using namespace std;

template<typename T>
class A
{
public:
	static int s; //������ģ�����͵ľ�̬��Ա
	static T s2;
};

//��̬��Ա��ʼ��
template<typename T>
int A<T>::s = 111;//ģ���ྲ̬��Ա�ĳ�ʼ��������������T����һ��ͨ�õ�ֵ

//��̬��Ա�ػ�
template<>
int A<int>::s = 222;   //ֻ���int������Ч

template<>
float A<float>::s2 = 1.234f;  //ֻ���ػ�

template<>
char A<char>::s2 = 'A';  //ֻ���ػ�


void main()
{
	//������ģ�����͵ľ�̬��Ա
	cout << A<float>::s << endl;
	cout << A<char>::s << endl;
	cout << A<double>::s << endl;
	cout << A<int>::s << endl;

	//����ģ�����͵ľ�̬��Ա
	cout << A<float>::s2 << endl;
	cout << A<char>::s2 << endl;


}