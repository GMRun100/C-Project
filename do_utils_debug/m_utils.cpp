#include"stdafx.h"
#include"m_utils.h"
#include"stdio.h"

LIBUTILS_API CString hello()
{
	//printf("hello world");
	//AfxMessageBox("Are you sure ? ",MB_YESNO | MB_ICONQUESTIO);
	CString str;
	str = "hello, world GM";
	return str;
 }