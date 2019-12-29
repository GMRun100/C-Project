#pragma once
//本示例中学习虚函数的一些使用
#include <afx.h>
typedef void(*Fun)(void);    //空函数指针，为测试虚函数使用  

class v_base
{
public:
	v_base();
	~v_base();
	virtual void g()
	{
		TRACE("v_base::g()\n");
	}

	virtual void f()
	{
		TRACE("v_base::f()\n");
	}

	virtual void h()
	{
		TRACE("v_base::h()\n");
	}

private:

};

v_base::v_base()
{
}

v_base::~v_base()
{
}
//一般继承，无虚函数覆盖情况
class v_Drived:public v_base
{
public:
	v_Drived();
	~v_Drived();
	virtual void g1()
	{
		TRACE("v_Drived::g1()\n");
	}

	virtual void f1()
	{
		TRACE("v_Drived::f1()\n");
	}

	virtual void h1()
	{
		TRACE("v_Drived::h1()\n");
	}


private:

};

v_Drived::v_Drived()
{
}

v_Drived::~v_Drived()
{
}

//一般继承：有虚函数覆盖的情况
class v_Drived2:public v_base
{
public:
	v_Drived2();
	~v_Drived2();

	virtual void g()
	{
		TRACE("v_Drived2::g()\n");
	}

	virtual void f2()
	{
		TRACE("v_Drived2::f2()\n");
	}

	virtual void h2()
	{
		TRACE("v_Drived2::h2()\n");
	}


private:

};

v_Drived2::v_Drived2()
{
}

v_Drived2::~v_Drived2()
{
}