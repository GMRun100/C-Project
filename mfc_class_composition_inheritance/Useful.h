#pragma once
//A class to resuse
#ifndef USEFUL_H
#define USEFUL_H


class X
{
	int i;    //���Աû��ʹ���κη������η������ٶ����ԱΪ˽�г�Ա
public:
	X() { i = 1; };
	X(int x_i) { i = x_i; }
	~X();
	void set(int ii)
	{ i = ii; }
	int read() const { return i; }     //����ֵΪ����
	int permute() { return i = i * 47; }

private:

};


X::~X()
{
}
#endif // !USEFUL_H