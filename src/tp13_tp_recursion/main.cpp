//ѧϰģ��ݹ�
//2019.10.26 GM

#include<iostream>
using namespace std;

//ʾ��һ
template<typename T>
class A
{
private:
	A<void> a;   //�����˵ݹ鶨��
};

//ͨ���ػ����ս�ݹ鶨��
template<>
class A<void>
{
};


//ʾ����
//���ñ������������
template<int N>
class Sum
{
public:
	enum//��ö�����ͣ���Ϊ�ñ������������ٱ����ڼ��Ƶ�ֵ
	{
		value = N + Sum<N - 1>::value
	};
};

template<>
class Sum<0>
{
public:
	enum
	{
		value = 0
	};
};


//ʾ����   ���ñ�����ʵ�ֶ�����תʮ����
//��ģ��
template<unsigned long N>
struct BinToDec
{
	static const unsigned val = BinToDec<N / 10>::val * 2 + N % 10;
};

template<>
struct BinToDec<0>  //�ػ�
{
	static const unsigned val = 0;
};

void main()
{
	//���ñ����ڵݹ�ʵ����ͺ���
	cout << Sum<100>::value << endl;

	//���ñ����ڵݹ�ʵ�ֶ�����תʮ����
	cout << BinToDec<10000>::val << endl;
}