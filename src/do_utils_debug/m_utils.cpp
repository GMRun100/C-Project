#include"stdafx.h"
#include"m_utils.h"
#include"stdio.h"

#include<io.h>
#include<fcntl.h>

//初始化控制台
void InitConsoleWindow()
{
	AllocConsole();
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	int hCrt = _open_osfhandle((long)handle, _O_TEXT);
	FILE * hf = _fdopen(hCrt, "w");
	*stdout = *hf;
	SetConsoleTitle(_T("GM console"));
	//freopen_s("CONOUT$","w+t", stdout);// 申请写
	//freopen_s("CONIN$", "r+t", stdin);  // 申请读
}

void freeConsoleWindow()
{
	FreeConsole();                      // 释放控制台资源
}

LIBUTILS_API CString hello()
{
	//printf("hello world");
	//AfxMessageBox("Are you sure ? ",MB_YESNO | MB_ICONQUESTIO);
	CString str;
	str = "hello, world GM";
	InitConsoleWindow();  // add
	_cwprintf_s(_T("haha\n"));    //向控制台中输出一些打印信息
	_cwprintf_s(_T("str = %s\n "), _T("Debug output goes to terminal\n"));
	//printf("str = %s\n ", "Debug output goes to terminal\n");
	//char ch = getchar();                // 读数据
	//freeConsoleWindow();   //程序执行完毕需要释放console窗口
	return str;
 }
