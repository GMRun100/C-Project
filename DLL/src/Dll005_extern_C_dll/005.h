#pragma once

//指示编译期这部分代码按C语言方式编译
extern "C" _declspec(dllexport) int sum(int a, int b);