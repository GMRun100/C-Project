// do_utils_debug.h : do_utils_debug DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Cdo_utils_debugApp
// �йش���ʵ�ֵ���Ϣ������� do_utils_debug.cpp
//

class Cdo_utils_debugApp : public CWinApp
{
public:
	Cdo_utils_debugApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
