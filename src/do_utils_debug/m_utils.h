#pragma once
//��ϰʹ����������
#define LIBUTILS_EXPORTS

#ifdef LIBUTILS_EXPORTS
#define LIBUTILS_API __declspec(dllexport)
#else
#define LIBUTILS_API __declspec(dllimport)
#endif
extern LIBUTILS_API  CString hello();
//extern LIBUTILS_API  int(*utils_debugA)(char *, ...);
