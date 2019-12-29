//ѧϰģ�������Ƶ�
//2019.10.26 GM

#include<iostream>
using namespace std;

//ʾ��һ
template<typename T>
void f1(T*)
{
	cout << typeid(T).name() << endl;
}

//ʾ����
template<typename T,int N> //���Ͳ���T,�����Ͳ���N
void f2(T(&p)[N]) //����pΪT[N]���������
{
	cout << N << "," << typeid(T).name() << "," << p[2] << endl;
}

//ʾ����
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


//ʾ����
template <int N>
class X
{
public:
	typedef int l;
	void f(int){}
};

template<int N>
//f4�Ĳ����Ǹ�X<N>�ĳ�Ա�������ú����ķ�������Ϊvoid,����һ��X<N>::l����
void f4(void (X<N>::* p)(typename X<N>::l))
{
	cout << N << " " << typeid(X<N>::l).name() << endl;
}


//ʾ����
template<typename T>
void f5(T t1)
{
	cout << typeid(T).name() << "," << t1 << endl;
}


//ʾ����
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

//ʾ��7
template<typename T>
void f8(T)
{
	cout << typeid(T).name() << endl;
}

template<typename T>
void f9(T &t)   //�������ã����鲻�ᱻ����ָ��
{
	cout << typeid(T).name() << endl;
}

//ʾ��8
//T & t��ʾ���ñ���
//T && t��ʾ������ֵ���ò���

template <typename T>
void f10(T&& t)  //��ֵ���Ƿ��ڵȺ��ұߵģ����糣��
{
	cout << typeid(t).name() << endl;
}

//ʾ��9
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
	//ģ�������Ƶ�
	int**** p=0;
	f1(p);   //���ͱ��Ƶ�Ϊint ***��

	int b[42] = { 1,2,3,4,5 };
	f2(b);

	char c[100] = { "hello" };
	f2(c);

	f3(&S::f);

	f4(&X<33>::f);


	//����ָ��f6
	void (*f6)(char) = &f5;//�Ƶ��ɹ�������T�滻Ϊchar,�Ա��ָ�ֵ�ĺϷ���
	f6('A');

	N<long> n1;
	M<float> m1;
	f7(n1);
	f7(m1);

	const char* p8 = "abc";
	f8(p8); //�Ƶ��ɹ���T���滻Ϊconst char*
	f9(p8); //�Ƶ��ɹ���T���滻Ϊconst char*
	double pp[20];
	f8(pp);	//�Ƶ��ɹ���T���滻Ϊdouble*
	f9(pp);	//�Ƶ��ɹ���T���滻Ϊdouble[20]


	int aa = 99;  //aa������ֵҲ����ֵ
	f10(aa);
	f10(100);
	f10(0.003);
	f10("sdfsf");

	f11<Y>();
}