#pragma once
#ifndef _TestDll_H_
#define _TestDLL_H_
#ifdef MYLIBDLL
#define MYLIBDLL extern "C" _declspec(dllimport)
#else
#define MYLIBDLL extern "C" _declspec(dllexport)
#endif



MYLIBDLL int Add(int plus1, int plus2);

#endif // _TestDll_H_

