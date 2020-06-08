// DLL004_test004.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//学习dll调用的第一种方式

#include <iostream>
//dll的第一种调用方式
//1.包含头文件
#include"DLL004_dll/004.h"
extern "C" _declspec(dllimport) int sum(int a, int b);  //这行代码好像不加也没事
//2.包含.lib文件
#pragma comment(lib,"DLL004_dll.lib")

//3.发布的时候.exe文件和.dll文件一起发布
//本cpp为调用dll的第一种方式
int main01()
{
    std::cout << sum(111, 222) << std::endl;
    //std::cout << "Hello World!\n";
    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
