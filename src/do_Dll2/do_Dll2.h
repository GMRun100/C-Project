#pragma once
#define DO_DLL2_EXPORTS

#ifdef DO_DLL2_EXPORTS
#define DO_DLL2_API __declspec(dllexport)
#else
#define DO_DLL2_API __declspec(dllimport)
#endif

extern "C" DO_DLL2_API double seekArea(int r, int h);