// FileSearching.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "GetSpecifiedFileFullPath.h"
#include "FileSearching.h"
#include "afxdialogex.h"


// CFileSearching �Ի���

IMPLEMENT_DYNAMIC(CFileSearching, CDialogEx)

CFileSearching::CFileSearching(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFileSearching::IDD, pParent)
{

}

CFileSearching::~CFileSearching()
{
}

void CFileSearching::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CFileSearching, CDialogEx)
END_MESSAGE_MAP()


// CFileSearching ��Ϣ�������
