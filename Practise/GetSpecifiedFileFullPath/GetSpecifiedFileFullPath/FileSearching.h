#pragma once


// CFileSearching �Ի���

class CFileSearching : public CDialogEx
{
	DECLARE_DYNAMIC(CFileSearching)

public:
	CFileSearching(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CFileSearching();

// �Ի�������
	enum { IDD = IDD_DLG_PROCESSING };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
