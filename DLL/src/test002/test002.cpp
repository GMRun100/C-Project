﻿// test002.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
//使用静态库的步骤
//1.包含头文件
#include"DLL002_lib/002.h"
//#pragma comment(lib,"E:\\02.Learning\\C++study\\DLL\\Debug\\DLL002_lib.lib")
//2.方法一:包含.lib文件
//#pragma comment(lib,"DLL002_lib.lib")
//2.方法二：右击项目->属性->配置属性->链接器->输入->附加依赖项 中添加此lib文件

//静态库程序发布的时候，不需要.lib文件，因为已经集成到.exe文件中了

int main()
{
    int res=sum(1, 2);
    std::cout << res << std::endl;
    getchar();
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
