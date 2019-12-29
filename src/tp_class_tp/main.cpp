//2019.10.21 GM  学习类模板

#include<iostream>
using namespace std;

//定义类模板
template<typename T>
class Math
{
public:
	//方法在类内实现，相当于内联函数
	T sum(T a, T b)
	{
		return a + b;
	}

	T max(T a, T b);
};

//方法在类外部实现
//模板类函数类的声明与实现必须放在同一个.h文件内
template<typename T>
T Math<T>::max(T a, T b)
{
	return a > b ? a : b;
}

int main()
{
	//定义模板类,实例化类模板
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