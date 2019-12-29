#include "stdafx.h"
#include "Distance.h"
#include <iostream>
using namespace std;
Distance::Distance()
{
	feet = 0;
	inches = 0;
}


Distance::~Distance()
{
}
Distance::Distance(int f, int i)
{
	feet = f;
	inches = i;
}
void Distance::operator=(const Distance &D)
{
	feet = D.feet;
	inches = D.inches;
}

void Distance::displayDistance()
{
	//cout << "F:" << feet << "I:" << inches << inches << endl;
	//���������Ϣ�����ַ�����
	CString str;
	str.Format(L"F:%d I:%d\n", feet, inches);
	OutputDebugString(str);

	TRACE("F:%d I:%d\n", feet, inches);
}