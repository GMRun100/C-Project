// do_utils_debug.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "do_utils_debug.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO:  ����� DLL ����� MFC DLL �Ƕ�̬���ӵģ�
//		��Ӵ� DLL �������κε���
//		MFC �ĺ������뽫 AFX_MANAGE_STATE ����ӵ�
//		�ú�������ǰ�档
//
//		����: 
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// �˴�Ϊ��ͨ������
//		}
//
//		�˺������κ� MFC ����
//		������ÿ��������ʮ����Ҫ��  ����ζ��
//		��������Ϊ�����еĵ�һ�����
//		���֣������������ж������������
//		������Ϊ���ǵĹ��캯���������� MFC
//		DLL ���á�
//
//		�й�������ϸ��Ϣ��
//		����� MFC ����˵�� 33 �� 58��
//

// Cdo_utils_debugApp

BEGIN_MESSAGE_MAP(Cdo_utils_debugApp, CWinApp)
END_MESSAGE_MAP()


// Cdo_utils_debugApp ����

Cdo_utils_debugApp::Cdo_utils_debugApp()
{
	// TODO:  �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� Cdo_utils_debugApp ����

Cdo_utils_debugApp theApp;


// Cdo_utils_debugApp ��ʼ��

BOOL Cdo_utils_debugApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
