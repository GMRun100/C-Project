#include"stdafx.h"
#include"m_utils.h"
#include"stdio.h"

#include<io.h>
#include<fcntl.h>

//��ʼ������̨
void InitConsoleWindow()
{
	AllocConsole();
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	int hCrt = _open_osfhandle((long)handle, _O_TEXT);
	FILE * hf = _fdopen(hCrt, "w");
	*stdout = *hf;
	SetConsoleTitle(_T("GM console"));
	//freopen_s("CONOUT$","w+t", stdout);// ����д
	//freopen_s("CONIN$", "r+t", stdin);  // �����
}

void freeConsoleWindow()
{
	FreeConsole();                      // �ͷſ���̨��Դ
}

LIBUTILS_API CString hello()
{
	//printf("hello world");
	//AfxMessageBox("Are you sure ? ",MB_YESNO | MB_ICONQUESTIO);
	CString str;
	str = "hello, world GM";
	InitConsoleWindow();  // add
	_cwprintf_s(_T("haha\n"));    //�����̨�����һЩ��ӡ��Ϣ
	_cwprintf_s(_T("str = %s\n "), _T("Debug output goes to terminal\n"));
	//printf("str = %s\n ", "Debug output goes to terminal\n");
	//char ch = getchar();                // ������
	//freeConsoleWindow();   //����ִ�������Ҫ�ͷ�console����
	return str;
 }
