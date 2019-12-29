//学习浅拷贝和深拷贝
//2019.10.12 GM

#include<iostream>

using namespace std;

class A
{
public:
	//构造函数
	A(const char* a)
	{
		int len = strlen(a) + 1;
		p = new char[len];
		memcpy(p,a,len);
	}

	//深拷贝，自定义拷贝构造函数
	A(const A& A1)
	{
		int len = strlen(A1.p) + 1;
		p = new char[len];
		memcpy(p, A1.p, len);
	}


	void print()
	{
		cout << p << endl;
	}
	char* p;
};

int main()
{
	A a1("Hello");
	a1.print();
	
	//此处我们采用了深拷贝的方式
	//如果采用浅拷贝,则a1.p=b1.p,两个指针都指向了同样的地址，任何一个对象修改了字符串值，另外一个对象的值也会一起变化
	A b1(a1);

	b1.print();

	memcpy(a1.p,"world",strlen("world")+1);

	a1.print();
	b1.print();
	 
	return 0;
}