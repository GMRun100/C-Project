#pragma once
#include <iostream>

using namespace std;


//������һ���������ص�����
class printData
{
public:
	printData();
	~printData();

	//�������أ���������Ϊ�����Ų��������Ͳ�ͬ����ͬ
	void print(int i)
	{
		cout << "����Ϊ��" << i << endl;
	}

	void print(double f)
	{
		cout << "������Ϊ��" << f << endl;
	}

	void print(char c[])
	{
		cout << "�ַ���Ϊ��" << c << endl;
	}

};

