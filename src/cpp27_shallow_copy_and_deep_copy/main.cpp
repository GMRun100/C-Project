//ѧϰǳ���������
//2019.10.12 GM

#include<iostream>

using namespace std;

class A
{
public:
	//���캯��
	A(const char* a)
	{
		int len = strlen(a) + 1;
		p = new char[len];
		memcpy(p,a,len);
	}

	//������Զ��忽�����캯��
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
	
	//�˴����ǲ���������ķ�ʽ
	//�������ǳ����,��a1.p=b1.p,����ָ�붼ָ����ͬ���ĵ�ַ���κ�һ�������޸����ַ���ֵ������һ�������ֵҲ��һ��仯
	A b1(a1);

	b1.print();

	memcpy(a1.p,"world",strlen("world")+1);

	a1.print();
	b1.print();
	 
	return 0;
}