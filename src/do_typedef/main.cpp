//ѧϰtypedef��ʹ�÷���

#include<iostream>

using namespace std;

void printHello(int i)
{
	cout << "i=" << i << endl;
}

//ʹ��typedef��������ָ��
typedef void(*PrintHelloHandle)(int);

//type�����ַ�������
typedef char Line[81];


int main()
{
	//ͨ���Ķ��庯��ָ��ķ���
	void (*pFun)(int);

	pFun = &printHello;

	(*pFun)(100);

	//ʹ��typedef��������ָ��
	
	PrintHelloHandle pFun2;
	pFun2 = &printHello;
	(*pFun2)(200);

	Line text[81];    //�൱��char text[81];


	getchar();

	return 1;
}




