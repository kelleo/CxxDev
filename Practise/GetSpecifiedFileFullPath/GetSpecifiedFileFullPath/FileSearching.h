#pragma once


// CFileSearching 对话框

class CFileSearching : public CDialogEx
{
	DECLARE_DYNAMIC(CFileSearching)

public:
	CFileSearching(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CFileSearching();

// 对话框数据
	enum { IDD = IDD_DLG_PROCESSING };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
