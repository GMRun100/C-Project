//学习typedef的使用方法

#include<iostream>

using namespace std;

void printHello(int i)
{
	cout << "i=" << i << endl;
}

//使用typedef声明函数指针
typedef void(*PrintHelloHandle)(int);

//type声明字符串数组
typedef char Line[81];


int main()
{
	//通常的定义函数指针的方法
	void (*pFun)(int);

	pFun = &printHello;

	(*pFun)(100);

	//使用typedef声明函数指针
	
	PrintHelloHandle pFun2;
	pFun2 = &printHello;
	(*pFun2)(200);

	Line text[81];    //相当于char text[81];


	getchar();

	return 1;
}




