#pragma once
//A class to resuse
#ifndef USEFUL_H
#define USEFUL_H


class X
{
	int i;    //���Աû��ʹ���κη������η������ٶ����ԱΪ˽�г�Ա
public:
	X() { i = 0; };
	~X();
	void set(int ii)
	{ i = ii; }
	int read() const { return i; }     //����ֵΪ����
	int permute() { return i = i * 47; }

private:

};

X::X()
{
}

X::~X()
{
}
#endif // !USEFUL_H