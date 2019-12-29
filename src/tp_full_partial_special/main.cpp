//ѧϰģ���ȫ�ػ���ƫ�ػ�
//2019.10.22 GM
#include<iostream>
using namespace std;

template <typename T1,typename T2>
class A
{
public:
	T1 a1;
	T2 a2;

	void print()
	{
		cout << "A <T1,T2>:print!" << endl;
	}
};


//���ȫ�ػ�,�ṹ����ģ�����豣��һ��
template <>
class A<int,float>
{
public:
	int a1;
	float a2;

	void print()
	{
		cout << "A <int,float>:print!" << endl;
	}
	void show()
	{
		cout << "A <int,float>:show!" << endl;
	}

};

//���ƫ�ػ�
template <typename T1>
class A<T1, float>
{
public:
	T1 a1;
	float a2;

	void print()
	{
		cout << "A <T1,float>:print!" << endl;
	}
	void show()
	{
		cout << "A <T1,float>:show!" << endl;
	}

};


template <>
class A<float, float>
{
public:
	int a1;
	float a2;

	void show()
	{
		cout << "A <float,float>:show!" << endl;
	}

};

//������ȫ�ػ�,����û��ƫ�ػ�����Ϊ������������
template <typename T1, typename T2>
void test(T1 a, T2 b)
{
	cout << "test <T1,T2>" << endl;
}

template<>
void test<int, int>(int a, int b)
{
	cout << "test <int, int>" << endl;
}

int main()
{
	//��ȫ�ػ�
	A<int, int> a;
	a.print();

	//ȫ�ػ�
	A<int, float> a2;
	a2.print();
	a2.show();

	A<float, float> a3;
	a3.show();

	//���ƫ�ػ�
	A<char, float> a4;
	a4.show();

	//������ȫ�ػ�
	test<int, float>(1, 2.01f);

	test<int, int>(1, 2);


	return 0;
}