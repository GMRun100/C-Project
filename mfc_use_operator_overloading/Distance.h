#pragma once

//本示例主要用来重载赋值运算符

class Distance
{
public:
	Distance();
	Distance(int f, int i);
	~Distance();

private:
	int feet;
	int inches;

public:
	void operator=(const Distance &D);
	void displayDistance();
};

