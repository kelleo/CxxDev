
// GetSpecifiedFileFullPath.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CGetSpecifiedFileFullPathApp: 
// �йش����ʵ�֣������ GetSpecifiedFileFullPath.cpp
//

class CGetSpecifiedFileFullPathApp : public CWinApp
{
public:
	CGetSpecifiedFileFullPathApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CGetSpecifiedFileFullPathApp theApp;