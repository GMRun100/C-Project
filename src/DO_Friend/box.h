#pragma once
//��ϰ��Ԫ��������Ԫ���ʹ��

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

//��Ԫ��
class BigBox
{
public:
	void print(int width, Box& box)
	{
		//BigBox��Box����Ԫ�࣬������ֱ�ӷ���Box����κγ�Ա
		box.setWidth(width);
		cout << "Width of box :" << box.width << endl;
	}

};

void Box::setWidth(double wid)
{
	width = wid;
}

//��Ԫ����
//�����Ԫ��������������ⲿ������Ȩ�����������˽�У�private����Ա�ͱ���(protected)��Ա��
//�����β�ʱ����ò��ó����ã���ֹ������Ŀ�������
void printWidth(const Box& box)
{
	cout << "Width of box :" << box.width << endl;
}