
// do_importDLL.h : do_importDLL 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// Cdo_importDLLApp:
// 有关此类的实现，请参阅 do_importDLL.cpp
//

class Cdo_importDLLApp : public CWinApp
{
public:
	Cdo_importDLLApp();


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cdo_importDLLApp theApp;
