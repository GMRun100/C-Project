#pragma once
#include <exception>
using namespace std;

class MyException :
	public exception       //这里要继承自exception类时，必须要注意添加std命名空间
{
public:
	MyException();
	~MyException();

	virtual const char* what() const throw()
	{
		return "My exception happened";
	}
};

