#pragma once
//本头文件主要研究父类声明子类实例化
#include <afxstr.h>
#include <afx.h>
//父类
class Employee
{
public:
	Employee();
	~Employee();
	CString name;
	virtual void getType()
	{
		TRACE("I am employee!\n");
	}

private:

};

Employee::Employee()
{
	TRACE("Employee start!\n");
}

Employee::~Employee()
{
}


class Manager:public Employee
{
public:
	Manager();
	~Manager();
	int money;
	void getType()
	{
		TRACE("I am Manager!\n");
	}

private:

};

Manager::Manager()
{
	TRACE("Manager start!\n");
}

Manager::~Manager()
{
}