#include<iostream>
using namespace std;
#include"DLL009_dllexport_class/009.h"
#pragma comment(lib,"DLL009_dllexport_class.lib")

int main()
{
	//Stu s(666);
	//s.Print();

	IAnimal* pCat = GetCat();
	pCat->eat();
	pCat->sleep();
	DelCat(pCat);

	return 0;
}