
// GetSpecifiedFileFullPathDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "GetSpecifiedFileFullPath.h"
#include "GetSpecifiedFileFullPathDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGetSpecifiedFileFullPathDlg 对话框



CGetSpecifiedFileFullPathDlg::CGetSpecifiedFileFullPathDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGetSpecifiedFileFullPathDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGetSpecifiedFileFullPathDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_FILENAME, m_etFilename);
	DDX_Control(pDX, IDC_EDIT_FILE_FULL_PATH, m_etFileFullPath);
	DDX_Control(pDX, IDC_BUTTON1, m_btFind);
}

BEGIN_MESSAGE_MAP(CGetSpecifiedFileFullPathDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CGetSpecifiedFileFullPathDlg::OnBnClickedSearch)
END_MESSAGE_MAP()


// CGetSpecifiedFileFullPathDlg 消息处理程序

BOOL CGetSpecifiedFileFullPathDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码
	m_btFind.SetFocus();

	if (!m_FileSearching.Create(IDD_DLG_PROCESSING, this))
	{
		AfxMessageBox(_T("创建进度对话框失败!"));
		return FALSE;
	}
	CRect rect;
	GetWindowRect(&rect);
	ClientToScreen(&rect);
	rect.InflateRect(-50, -30);

	m_FileSearching.MoveWindow(rect);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CGetSpecifiedFileFullPathDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CGetSpecifiedFileFullPathDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CGetSpecifiedFileFullPathDlg::OnBnClickedSearch()
{
	// 查找指定文件的全路径
	CString strFilename;
	m_etFilename.GetWindowText(strFilename);

	if (strFilename.IsEmpty())
	{
		AfxMessageBox(_T("文件名不能为空!"));
		return;
	}

	m_FileSearching.ShowWindow(SW_SHOW);
	SetCursor(LoadCursor(NULL, IDC_WAIT));

	vector<CString> vecResults;
	int nFileFound = GetSpecifiedFileFullPath(_T("C:\\"), strFilename, vecResults);

	SetCursor(LoadCursor(NULL, IDC_ARROW));
	m_FileSearching.ShowWindow(SW_HIDE);

	if (nFileFound)
	{
		m_etFileFullPath.SetWindowTextW(vecResults[0]);
	}
	else
	{
		CString strErrInfo;
		strErrInfo.Format(_T("没有找到文件[%s]!"),strFilename.GetBuffer());
		AfxMessageBox(strErrInfo);
	}
}

const CString CGetSpecifiedFileFullPathDlg::GetCurrentFileDir()
{
	//获取当前可执行文件的路径，不包括文件名
	TCHAR szFilePath[MAX_PATH + 1];
	GetModuleFileName(NULL, szFilePath, MAX_PATH);
	(_tcsrchr(szFilePath, _T('\\')))[0] = 0;//删除文件名，只获得路径
	CString str_url = szFilePath;
	return str_url;
}

int CGetSpecifiedFileFullPathDlg::GetSpecifiedFileFullPath(const CString strDir, const CString strFilename, vector<CString>& vecRslt)
{
	CString strPath = strDir;

	//检查给定的路径的最后一个字符是不是'\'，如果不是，则加上
	if (strPath.Right(1) != "\\")
	{
		strPath += _T("\\");
	}
	CString strFindPath = strPath + _T("*.*");

	//开始查找指定的文件
	CFileFind finder;
	BOOL bWorking = finder.FindFile(strFindPath);
	while (bWorking)
	{
		bWorking = finder.FindNextFile();
		//如果找到的是文件夹且不是"."或".."的文件夹，则递归
		if (finder.IsDirectory() && !finder.IsDots())
		{
			GetSpecifiedFileFullPath(strPath + finder.GetFileName(), strFilename, vecRslt);
		}
		//如果找到了文件，将绝对路径添加进字符串数组,大小写不敏感  
		if (finder.GetFileName().CompareNoCase(strFilename) == 0)
		{
			vecRslt.push_back(finder.GetFilePath());
		}
	}

	//返回找到的文件个数  
	return  vecRslt.size();
}
