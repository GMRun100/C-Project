//学习模板的全特化和偏特化
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


//类的全特化,结构与主模板无需保持一致
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

//类的偏特化
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

//函数的全特化,函数没有偏特化，因为函数可以重载
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
	//非全特化
	A<int, int> a;
	a.print();

	//全特化
	A<int, float> a2;
	a2.print();
	a2.show();

	A<float, float> a3;
	a3.show();

	//类的偏特化
	A<char, float> a4;
	a4.show();

	//函数的全特化
	test<int, float>(1, 2.01f);

	test<int, int>(1, 2);


	return 0;
}