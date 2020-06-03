#include<iostream>
#include<functional>
using namespace std;

//һԪ��������(�º���)

//struct IsOdd
//{
//	bool operator()(int a)   //�˴�ֻ��һ������
//	{
//		return a % 2 == 1;
//	}
//
//};




struct IsOdd:public unary_function<int,bool>
{
	result_type operator()(argument_type a)   //�˴�ֻ��һ������
	{
		return a % 2 == 1;
	}

};


//��Ԫ��������
//struct Min
//{
//	int  operator()(const int& a, const int& b)
//	{
//		return a < b ? a : b;
//	}
//};


//��Ԫ�������󣬼̳еķ���
struct Min:public binary_function<const int & ,const int &,int>
{
	result_type  operator()(first_argument_type a, second_argument_type b)
	{
		return a < b ? a : b;
	}
};


void main()
{
	//����һ������
	IsOdd::argument_type a = 111;
	IsOdd::result_type ret = IsOdd()(111);
	cout << "�Ƿ�������:" << ret << endl;

	Min::first_argument_type a2 = 111;

	Min::second_argument_type b2 = 222;
	Min::result_type c = Min()(a2, b2);
	cout << "��Сֵ��:" << c << endl;
	


}