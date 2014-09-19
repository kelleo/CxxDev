
// GetSpecifiedFileFullPathDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "FileSearching.h"
#include <vector>
using namespace std;

// CGetSpecifiedFileFullPathDlg 对话框
class CGetSpecifiedFileFullPathDlg : public CDialogEx
{
// 构造
public:
	CGetSpecifiedFileFullPathDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_GETSPECIFIEDFILEFULLPATH_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

	const CString GetCurrentFileDir();

	int GetSpecifiedFileFullPath(const CString strDir, const CString strFilename, vector<CString>& vecRslt);
// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	// 待获取路径的文件
	CEdit m_etFilename;
	// 文件的全路径，不包括文件名
	CEdit m_etFileFullPath;
	// 查找指定文件的全路径
	CButton m_btFind;
	CFileSearching m_FileSearching;
	afx_msg void OnBnClickedSearch();
};
