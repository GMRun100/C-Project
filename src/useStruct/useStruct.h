
// useStruct.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CuseStructApp: 
// �йش����ʵ�֣������ useStruct.cpp
//

class CuseStructApp : public CWinApp
{
public:
	CuseStructApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CuseStructApp theApp;