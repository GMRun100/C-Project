#pragma once
//��ʾ����ѧϰ�麯����һЩʹ��
#include <afx.h>
typedef void(*Fun)(void);    //�պ���ָ�룬Ϊ�����麯��ʹ��  

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
//һ��̳У����麯���������
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

//һ��̳У����麯�����ǵ����
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