
// GetCmdLineParaDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include <string>

using namespace std;


// CGetCmdLineParaDlg �Ի���
class CGetCmdLineParaDlg : public CDialogEx
{
// ����
public:
	CGetCmdLineParaDlg(CWnd* pParent = NULL);	// ��׼���캯��

	void SetParam(string sParam);

// �Ի�������
	enum { IDD = IDD_GETCMDLINEPARA_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CStatic m_stParam; 
	string m_sParam;
};
