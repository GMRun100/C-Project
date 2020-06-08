#include<iostream>
#define _DLL_EXPORT
#include"006.h"
using namespace std;

DLL_API void fun()
{
	std::cout << "fun" << std::endl;
}