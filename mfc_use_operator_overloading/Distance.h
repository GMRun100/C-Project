#pragma once

//��ʾ����Ҫ�������ظ�ֵ�����

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

