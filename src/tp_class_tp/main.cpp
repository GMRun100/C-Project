//2019.10.21 GM  ѧϰ��ģ��

#include<iostream>
using namespace std;

//������ģ��
template<typename T>
class Math
{
public:
	//����������ʵ�֣��൱����������
	T sum(T a, T b)
	{
		return a + b;
	}

	T max(T a, T b);
};

//���������ⲿʵ��
//ģ���ຯ�����������ʵ�ֱ������ͬһ��.h�ļ���
template<typename T>
T Math<T>::max(T a, T b)
{
	return a > b ? a : b;
}

int main()
{
	//����ģ����,ʵ������ģ��
	Math<int> math1;
	cout<<math1.sum(2, 3)<<endl;
	cout << math1.max(6, 7) << endl;

	Math<float> math2;
	cout << math2.sum(2.234f, 3.567f) << endl;
	cout << math2.max(2.234f, 3.567f) << endl;

	Math<double> math3;
	cout << math3.sum(2.234, 3.567) << endl;
	cout << math3.max(2.234, 3.567) << endl;

	return 0;
}