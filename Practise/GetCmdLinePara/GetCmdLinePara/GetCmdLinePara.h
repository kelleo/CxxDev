
// GetCmdLinePara.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������
#include <string>

using namespace std;

// CGetCmdLineParaApp: 
// �йش����ʵ�֣������ GetCmdLinePara.cpp
//

class CGetCmdLineParaApp : public CWinApp
{
public:
	CGetCmdLineParaApp();
	const string ToString(CString str);

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CGetCmdLineParaApp theApp;