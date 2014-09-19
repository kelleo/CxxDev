
// GetSpecifiedFileFullPathDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "GetSpecifiedFileFullPath.h"
#include "GetSpecifiedFileFullPathDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGetSpecifiedFileFullPathDlg �Ի���



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


// CGetSpecifiedFileFullPathDlg ��Ϣ�������

BOOL CGetSpecifiedFileFullPathDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	m_btFind.SetFocus();

	if (!m_FileSearching.Create(IDD_DLG_PROCESSING, this))
	{
		AfxMessageBox(_T("�������ȶԻ���ʧ��!"));
		return FALSE;
	}
	CRect rect;
	GetWindowRect(&rect);
	ClientToScreen(&rect);
	rect.InflateRect(-50, -30);

	m_FileSearching.MoveWindow(rect);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CGetSpecifiedFileFullPathDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CGetSpecifiedFileFullPathDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CGetSpecifiedFileFullPathDlg::OnBnClickedSearch()
{
	// ����ָ���ļ���ȫ·��
	CString strFilename;
	m_etFilename.GetWindowText(strFilename);

	if (strFilename.IsEmpty())
	{
		AfxMessageBox(_T("�ļ�������Ϊ��!"));
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
		strErrInfo.Format(_T("û���ҵ��ļ�[%s]!"),strFilename.GetBuffer());
		AfxMessageBox(strErrInfo);
	}
}

const CString CGetSpecifiedFileFullPathDlg::GetCurrentFileDir()
{
	//��ȡ��ǰ��ִ���ļ���·�����������ļ���
	TCHAR szFilePath[MAX_PATH + 1];
	GetModuleFileName(NULL, szFilePath, MAX_PATH);
	(_tcsrchr(szFilePath, _T('\\')))[0] = 0;//ɾ���ļ�����ֻ���·��
	CString str_url = szFilePath;
	return str_url;
}

int CGetSpecifiedFileFullPathDlg::GetSpecifiedFileFullPath(const CString strDir, const CString strFilename, vector<CString>& vecRslt)
{
	CString strPath = strDir;

	//��������·�������һ���ַ��ǲ���'\'��������ǣ������
	if (strPath.Right(1) != "\\")
	{
		strPath += _T("\\");
	}
	CString strFindPath = strPath + _T("*.*");

	//��ʼ����ָ�����ļ�
	CFileFind finder;
	BOOL bWorking = finder.FindFile(strFindPath);
	while (bWorking)
	{
		bWorking = finder.FindNextFile();
		//����ҵ������ļ����Ҳ���"."��".."���ļ��У���ݹ�
		if (finder.IsDirectory() && !finder.IsDots())
		{
			GetSpecifiedFileFullPath(strPath + finder.GetFileName(), strFilename, vecRslt);
		}
		//����ҵ����ļ���������·����ӽ��ַ�������,��Сд������  
		if (finder.GetFileName().CompareNoCase(strFilename) == 0)
		{
			vecRslt.push_back(finder.GetFilePath());
		}
	}

	//�����ҵ����ļ�����  
	return  vecRslt.size();
}
