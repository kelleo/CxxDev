// TaskSch.cpp : �������̨Ӧ�ó������ڵ㡣
// at �����api�汾�����������൱��ִ��at 22:21 C:\WIndows\system32\notepad.exe

#include "stdafx.h"

#include "stdafx.h"
#include <stdio.h>
#include <windows.h>
#include <lmcons.h>
#include <lmat.h>
#include <IOSTREAM>

#pragma comment(lib,"NETAPI32.LIB")

void Jobadd() {
	DWORD JobId, ret;
	AT_INFO ai;
	TCHAR *filepath;
	TCHAR RootPath[MAX_PATH];
	GetSystemDirectory(RootPath, MAX_PATH);
	filepath = new TCHAR[wcslen(RootPath) + MAX_PATH];
	wcscpy_s(filepath, wcslen(RootPath)+10 , RootPath);
	TCHAR *strPadPath = _T("\\notepad.exe");
	int len = wcslen(strPadPath);
	wcscat_s(filepath, wcslen(RootPath) + MAX_PATH-2, strPadPath); //����·��
	memset(&ai, 0, sizeof(ai));
	ai.Command = filepath;
	ai.DaysOfMonth = 0;
	ai.DaysOfWeek = 0x7F; //7F���ڶ����Ƶ�7��1������ÿ�ܵ�7��ȫ������
	ai.Flags = JOB_RUN_PERIODICALLY;
	ai.JobTime = 22 * 60 * 60 * 1000 + 21 * 60 * 1000; //22��21�֣��������Ժ���Ϊ��λ�ģ�������Ҫ����Щֵ
	ret = NetScheduleJobAdd(NULL, LPBYTE(&ai), &JobId);
	if (ret == ERROR_SUCCESS)
		std::cout << " SUCCESS!!"<< "job time is : "<< ai.JobTime/60/1000/60<<":"<<ai.JobTime/60/1000%60 << std::endl;
	else
		std::cout << "Error" << std::endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	Jobadd();
	return 0;
}

