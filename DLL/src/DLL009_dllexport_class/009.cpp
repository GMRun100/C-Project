#include"009.h"
#include<iostream>
using namespace std;
/*
Stu::Stu(int id)
{
	this->id = id;
}

void Stu::Print()
{
	cout << id << endl;
}
*/


class Cat :public IAnimal
{
public:
	Cat(int age)
	{
		this->age = age;
		cout << "è����" << endl;
	}
	virtual void eat()
	{
		cout << "è����" << endl;
	}

	virtual void sleep()
	{
		cout << "è˯��" << endl;
	}

	virtual ~Cat()
	{
		cout << "è����" << endl;
	}

private:
	int age;

};



//����һ��������������
_declspec(dllexport) IAnimal* GetCat()
{

	return new Cat(6);
}

_declspec(dllexport) bool DelCat(IAnimal* animal)
{
	delete (Cat*)animal;
	return true;
}