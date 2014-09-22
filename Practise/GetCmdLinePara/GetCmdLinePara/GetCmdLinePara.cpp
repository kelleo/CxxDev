
// GetCmdLinePara.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "GetCmdLinePara.h"
#include "GetCmdLineParaDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include <string>

using namespace std;

// CGetCmdLineParaApp

BEGIN_MESSAGE_MAP(CGetCmdLineParaApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CGetCmdLineParaApp ����

CGetCmdLineParaApp::CGetCmdLineParaApp()
{
	// TODO:  �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CGetCmdLineParaApp ����

CGetCmdLineParaApp theApp;


// CGetCmdLineParaApp ��ʼ��

BOOL CGetCmdLineParaApp::InitInstance()
{
	CWinApp::InitInstance();


	// ���� shell ���������Է��Ի������
	// �κ� shell ����ͼ�ؼ��� shell �б���ͼ�ؼ���
	CShellManager *pShellManager = new CShellManager;

	// ���Windows Native���Ӿ����������Ա��� MFC �ؼ�����������
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO:  Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

	//��ȡ�������ϴ��ݵĲ���
	int nums = 0;

	TCHAR** pParam = CommandLineToArgvW(GetCommandLine(), &nums);

	CString strParam1 = pParam[1];

	CGetCmdLineParaDlg dlg;
	dlg.SetParam(ToString(pParam[1]));
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO:  �ڴ˷��ô����ʱ��
		//  ��ȷ�������رնԻ���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO:  �ڴ˷��ô����ʱ��
		//  ��ȡ�������رնԻ���Ĵ���
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "����: �Ի��򴴽�ʧ�ܣ�Ӧ�ó���������ֹ��\n");
		TRACE(traceAppMsg, 0, "����: ������ڶԻ�����ʹ�� MFC �ؼ������޷� #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS��\n");
	}

	// ɾ�����洴���� shell ��������
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	return FALSE;
}

const string CGetCmdLineParaApp::ToString(CString str)
{
	char *pszBuffer = new char[str.GetLength() + 1];
	WideCharToMultiByte(CP_ACP, 0, str.GetBuffer(), -1, pszBuffer, str.GetLength() + 1, NULL, NULL);

	string strResult = pszBuffer;

	delete[] pszBuffer;

	return strResult;
}

