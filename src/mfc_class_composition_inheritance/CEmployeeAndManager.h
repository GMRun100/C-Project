#pragma once
//��ͷ�ļ���Ҫ�о�������������ʵ����
#include <afxstr.h>
#include <afx.h>
//����
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