#include<iostream>
using namespace std;
#include"DLL009_dllexport_class/009.h"
#pragma comment(lib,"DLL009_dllexport_class.lib")

int main()
{
	Stu s(666);
	s.Print();

	return 0;
}