//学习模板类型推导
//2019.10.26 GM

#include<iostream>
using namespace std;

//示例一
template<typename T>
void f1(T*)
{
	cout << typeid(T).name() << endl;
}

//示例二
template<typename T,int N> //类型参数T,非类型参数N
void f2(T(&p)[N]) //参数p为T[N]数组的引用
{
	cout << N << "," << typeid(T).name() << "," << p[2] << endl;
}

//示例三
class S
{
public:
	void f(double*){}
};

template<typename T1, typename T2, typename T3>
void f3(T1(T2::*)(T3*))
{
	cout << typeid(T1).name() << " " << typeid(T2).name() << " " << typeid(T3).name() << endl;
}


//示例四
template <int N>
class X
{
public:
	typedef int l;
	void f(int){}
};

template<int N>
//f4的参数是个X<N>的成员函数，该函数的返回类型为void,接收一个X<N>::l参数
void f4(void (X<N>::* p)(typename X<N>::l))
{
	cout << N << " " << typeid(X<N>::l).name() << endl;
}


//示例五
template<typename T>
void f5(T t1)
{
	cout << typeid(T).name() << "," << t1 << endl;
}


//示例六
template<typename T>
class M
{

};

template<typename T>
class N:public M<T>
{

};
template<typename T>
void f7(M<T>)
{
	cout << typeid(T).name() << endl;
}

//示例7
template<typename T>
void f8(T)
{
	cout << typeid(T).name() << endl;
}

template<typename T>
void f9(T &t)   //加了引用，数组不会被当成指针
{
	cout << typeid(T).name() << endl;
}

//示例8
//T & t表示引用变量
//T && t表示可以右值引用参数

template <typename T>
void f10(T&& t)  //右值就是放在等号右边的，比如常量
{
	cout << typeid(t).name() << endl;
}

//示例9
class Y
{
public:
	typedef float vType;
};
template<typename T>
void f11()
{
	typename T::vType t;
	cout << typeid(t).name() << endl;
}



void main()
{
	//模板类型推导
	int**** p=0;
	f1(p);   //类型被推导为int ***，

	int b[42] = { 1,2,3,4,5 };
	f2(b);

	char c[100] = { "hello" };
	f2(c);

	f3(&S::f);

	f4(&X<33>::f);


	//函数指针f6
	void (*f6)(char) = &f5;//推导成功，并将T替换为char,以保持赋值的合法性
	f6('A');

	N<long> n1;
	M<float> m1;
	f7(n1);
	f7(m1);

	const char* p8 = "abc";
	f8(p8); //推导成功，T被替换为const char*
	f9(p8); //推导成功，T被替换为const char*
	double pp[20];
	f8(pp);	//推导成功，T被替换为double*
	f9(pp);	//推导成功，T被替换为double[20]


	int aa = 99;  //aa既是左值也是右值
	f10(aa);
	f10(100);
	f10(0.003);
	f10("sdfsf");

	f11<Y>();
}