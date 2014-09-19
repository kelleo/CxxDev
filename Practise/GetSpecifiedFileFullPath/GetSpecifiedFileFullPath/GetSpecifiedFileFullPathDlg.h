
// GetSpecifiedFileFullPathDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "FileSearching.h"
#include <vector>
using namespace std;

// CGetSpecifiedFileFullPathDlg �Ի���
class CGetSpecifiedFileFullPathDlg : public CDialogEx
{
// ����
public:
	CGetSpecifiedFileFullPathDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_GETSPECIFIEDFILEFULLPATH_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

	const CString GetCurrentFileDir();

	int GetSpecifiedFileFullPath(const CString strDir, const CString strFilename, vector<CString>& vecRslt);
// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	// ����ȡ·�����ļ�
	CEdit m_etFilename;
	// �ļ���ȫ·�����������ļ���
	CEdit m_etFileFullPath;
	// ����ָ���ļ���ȫ·��
	CButton m_btFind;
	CFileSearching m_FileSearching;
	afx_msg void OnBnClickedSearch();
};
