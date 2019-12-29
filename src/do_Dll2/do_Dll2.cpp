// do_Dll2.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "do_Dll2.h"
#include<iostream>
using namespace std;

static void show()
{
	cout << "Call the DLL2 function" << endl;
}

double area(int r) {
	return 3.14*r*r;
}

DO_DLL2_API double seekArea(int r, int h) {
	show();
	double under = 3.14*r*r;
	double v = under * h;
	return v;
}


