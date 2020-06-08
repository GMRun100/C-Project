#include<iostream>
using namespace std;

//#include"DLL006_dll/006.h"   //方式一
#include"main.h"    //方式二  更规范
#pragma comment(lib,"DLL006_dll.lib")
int main()
{
	fun();

	return 0;
}