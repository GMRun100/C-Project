//ѧϰ������if switch�ṹ
//2019.10.26 GM 

#include<iostream>
using namespace std;

//��ģ��
template<bool b>  //�����Ͳ���
struct If   //ע�����ﲻ����if�ؼ���
{};


//ȫ�ػ���Ϊ���ʱ��ִ��
template<>  
struct If<true>
{
	static void fun()
	{
		cout << "Ϊ��ִ����䣡" << endl;
	}
};
//ȫ�ػ���Ϊ�ٵ�ʱ��ִ��
template<>
struct If<false>
{
	static void fun()
	{
		cout << "Ϊ��ִ����䣡" << endl;
	}
};

//switch��ģ��
template<int Case>
struct Switch
{
	static void f()
	{
		cout << "ִ��default���" << endl;
	}
};

//ȫ�ػ���CaseΪ1ʱִ��
template<>
struct Switch<1>
{
	static void f()
	{
		cout << "ִ��Case1���" << endl;
	}
};

//ȫ�ػ���CaseΪ2ʱִ��
template<>
struct Switch<2>
{
	static void f()
	{
		cout << "ִ��Case2���" << endl;
	}
};

void main()
{
	//�����ڵ�if�ṹ
	If<true>::fun();
	If<false>::fun();

	//�����ڵ�switch�ṹ
	Switch<1>::f();
	Switch<2>::f();
	Switch<99>::f();

}