
// do_importDLL.h : do_importDLL Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// Cdo_importDLLApp:
// �йش����ʵ�֣������ do_importDLL.cpp
//

class Cdo_importDLLApp : public CWinApp
{
public:
	Cdo_importDLLApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cdo_importDLLApp theApp;
