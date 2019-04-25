#pragma once
//A class to resuse
#ifndef USEFUL_H
#define USEFUL_H


class X
{
	int i;    //类成员没有使用任何访问修饰符，将假定类成员为私有成员
public:
	X() { i = 1; };
	X(int x_i) { i = x_i; }
	~X();
	void set(int ii)
	{ i = ii; }
	int read() const { return i; }     //返回值为常量
	int permute() { return i = i * 47; }

private:

};


X::~X()
{
}
#endif // !USEFUL_H