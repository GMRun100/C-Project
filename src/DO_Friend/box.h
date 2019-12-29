#pragma once
//练习友元函数，友元类的使用

#include<iostream>
using namespace std;

class Box
{
private:
	double width;
public:
	friend void printWidth(const Box& box);
	friend class BigBox;
	void setWidth(double wid);
};

//友元类
class BigBox
{
public:
	void print(int width, Box& box)
	{
		//BigBox是Box的友元类，它可以直接访问Box类的任何成员
		box.setWidth(width);
		cout << "Width of box :" << box.width << endl;
	}

};

void Box::setWidth(double wid)
{
	width = wid;
}

//友元函数
//类的友元函数定义在类的外部，但有权访问类的所有私有（private）成员和保护(protected)成员。
//类做形参时，最好采用常引用，防止调用类的拷贝函数
void printWidth(const Box& box)
{
	cout << "Width of box :" << box.width << endl;
}