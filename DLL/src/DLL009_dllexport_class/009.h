#pragma once

//学习DLL 导出C++类
//2020.06.10 GM 
/*
class _declspec(dllexport) Stu
{
public:
	Stu(int id);
	void Print();
private:
	int id;
};
*/


//更好的导出类的方式
//接口类
class IAnimal
{
public:
	virtual void eat() = 0;
	virtual void sleep() = 0;
};


_declspec(dllexport) IAnimal* GetCat();
_declspec(dllexport) bool DelCat(IAnimal* animal);
