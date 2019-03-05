// use_strType.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//本程序中主要练习一些字符串的使用，及字符串的相互转化等等
//本程序为控制台程序

#include "pch.h"
#include <iostream>
#include<io.h>
#include<wtypes.h>
typedef int *pint;    //此处相当于定义了一个int型的指针类型
int main()
{
    //std::cout << "Hello World!\n"; 
	char greeting[6] = { 'H','e','l','l','o','\0' };
	char greeting2[] = "hello";  //字符串实际上是使用 null 字符 '\0' 终止的一维字符数组

	//使用sizeof计算字符串数组长度
	int num_greeting;
	num_greeting =sizeof(greeting);
	int num_greeting2;
	num_greeting2 = sizeof(greeting2);   //由于在数组的末尾存储了空字符，所以字符数组的大小比单词 "Hello" 的字符数多一个,输出为6

	//使用strlen计算字符串长度
	int strlen_greeting;
	strlen_greeting=strlen(greeting);		//此处返回的是字符串的长度，并不包括空字符，所以返回5
	int strlen_greeting2;
	strlen_greeting2 = strlen(greeting2);

	pint m_pint;   //此处练习typedef的使用
	int n;
	n = 10;
	m_pint = &n;
	std::cout << "m_pint =" << *m_pint << "\n";

	//LPSTR:长指针字符串，L代表长，P代表指针，STR表示字符串
	//我们通过查找官方的定义：typedef _Null_terminated_ CHAR *NPSTR, *LPSTR, *PSTR; 
	//通过官方的定义可以LPSTR为以NULL为终止的字符串指针
	LPSTR m_LPSTR;
	int len_LPSTR;
	len_LPSTR = sizeof(m_LPSTR);  //在x86平台下，指针长度为4个字节，在x64平台下，指针长度为8个字节
	m_LPSTR = greeting;
	std::cout << "m_LPSTR =" << *m_LPSTR << "\n";   //此处m_LPSTR指向字符串的首地址，所以只打印H

	//LPSTR 转化为string 
	//CString str(m_LPSTR);
	
	//PSTR:窄指针字符串
	PSTR m_PSTR;
	int len_PSTR;
	len_PSTR = sizeof(m_PSTR);	//在x86平台下，指针长度为4个字节，在x64平台下，指针长度为8个字节，没感觉出跟LPSTR有啥区别
	m_PSTR = greeting2;
	std::cout << "m_PSTR =" << *m_PSTR << "\n";




	

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
