//ѧϰ����ģ��
//2019.10.20 GM

#include<iostream>
using namespace std;

//����ģ��
template <typename T>
inline T sum(T a, T b)    //����ģ��Ҳ���Ա�����Ϊ��������
{
	//typedef double T;  //������������ģ�����Type,������T����
	return a + b;
}

//������Ͳ���,ƽʱ�����÷�����
template <typename T1,typename T2,class T3>
T3 sum(T1 a, T2 b)
{
	//typedef double T;  //������������ģ�����Type,������T����
	T3 tmp = a + b;
	return tmp;
}

int main()
{
	//ģ�庯��
	//�������
	int a=sum<int>(111, 222);
	cout << a << endl;

	//���������
	float f = sum<float>(1.234f, 4.567f);
	cout << f << endl;

	//˫�������
	double d = sum<double>(1.234, 4.567);
	cout << d << endl;



	//���������ģ��
	double d2 = sum<int, float,double>(100, 1.234f);
	cout << d2 << endl;



}