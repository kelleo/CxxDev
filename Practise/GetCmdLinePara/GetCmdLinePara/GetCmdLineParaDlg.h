
// GetCmdLineParaDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include <string>

using namespace std;


// CGetCmdLineParaDlg 对话框
class CGetCmdLineParaDlg : public CDialogEx
{
// 构造
public:
	CGetCmdLineParaDlg(CWnd* pParent = NULL);	// 标准构造函数

	void SetParam(string sParam);

// 对话框数据
	enum { IDD = IDD_GETCMDLINEPARA_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CStatic m_stParam; 
	string m_sParam;
};
