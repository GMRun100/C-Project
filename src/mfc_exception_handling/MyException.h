#pragma once
#include <exception>
using namespace std;

class MyException :
	public exception       //����Ҫ�̳���exception��ʱ������Ҫע�����std�����ռ�
{
public:
	MyException();
	~MyException();

	virtual const char* what() const throw()
	{
		return "My exception happened";
	}
};

