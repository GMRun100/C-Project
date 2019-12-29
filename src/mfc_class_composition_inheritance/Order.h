#pragma once
#include <afx.h>
//Constructor/destructor order

//typedef class ID CLASS(ID)
//{ 
//public:
//	ID(int) { TRACE("%s constructor",ID);}
//	~ID(){TRACE("%s destructor",ID);}
//}; 
//
//CLASS(Base1);
//CLASS(Member1);
//CLASS(Member2);
//CLASS(Member3);
//CLASS(Member4);

class Base1
{
public:
	Base1(int)
	{
		TRACE("Base1 constructor\n");
	};
	~Base1()
	{
		TRACE("Base1 destructor\n");
	};

private:
};

class Member1
{
public:
	Member1(int)
	{
		TRACE("Member1 constructor\n");
	};
	~Member1() 
	{
		TRACE("Member1 destructor\n");
	};

private:
};
class Member2
{
public:
	Member2(int)
	{
		TRACE("Member2 constructor\n");
	};
	~Member2() 
	{
		TRACE("Member2 destructor\n");
	};

private:
};

class Member3
{
public:
	Member3(int)
	{
		TRACE("Member3 constructor\n");
	};
	~Member3() 
	{
		TRACE("Member3 destructor\n");
	};

private:
};

class Member4
{
public:
	Member4(int)
	{
		TRACE("Member4 constructor\n");
	};
	~Member4() 
	{
		TRACE("Member4 destructor\n");
	};

private:
};

class Derived1:public Base1
{
private:
	Member1 m1;
	Member2 m2;

public:
	Derived1(int) :m2(1),m1(2),Base1(3){
		TRACE("Derived1 constructor\n");
	};
	~Derived1() 
	{
		TRACE("Derived1 destructor\n");
	};
};

class Derived2 :public Derived1
{
private:
	Member3 m3;
	Member4 m4;

public:
	//first call Derived1();���Ȼ���û��๹�캯����Ȼ����ó�Ա�������캯��
	//���ڳ�Ա���󣬹��캯�����õĴ�����ȫ���ܹ��캯���ĳ�ʼ�����ʽ�е�Ӱ�죬�ô������ɳ�Ա���������������Ĵ�����������
	Derived2(int) :m3(1), Derived1(2), m4(3) {
		TRACE("Derived2 constructor\n");
	};
	~Derived2() 
	{
		TRACE("Derived2 destructor\n");
	};
};


