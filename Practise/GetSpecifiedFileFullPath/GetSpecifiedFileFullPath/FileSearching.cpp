// FileSearching.cpp : 实现文件
//

#include "stdafx.h"
#include "GetSpecifiedFileFullPath.h"
#include "FileSearching.h"
#include "afxdialogex.h"


// CFileSearching 对话框

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


// CFileSearching 消息处理程序
