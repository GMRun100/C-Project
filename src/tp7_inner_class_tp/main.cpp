//学习内部类模板
//2019.10.22 GM
#include<iostream>
using namespace std;
//外部类
template<typename T>
class Outer
{
public:
	//内部类
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

//知识点来了,需要两级模板声明
template<typename T>
template<typename T2>
void Outer<T>::Inner<T2>::print()
{
	cout << "Inner print" << endl;
}
void main()
{
	//外部类对象
	Outer<int> o;
	o.print();

	//内部类对象，需加上作用于限定符
	Outer<int>::Inner<int> i;
	i.print();
}