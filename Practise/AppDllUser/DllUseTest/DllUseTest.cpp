// DllUseTest.cpp : �������̨Ӧ�ó������ڵ㡣
// Dll�Ĳ��Թ��̣����ڲ���Dll�еĺ����Ƿ����Dll����е���

#include "stdafx.h"
#include "..\SerializeDll\structs.h"
#include <windows.h>
#include <iostream>

using namespace std;

//����Dll��Ӧ�ĺ���ָ��
typedef void (*lpSer)(PRJ_TABLE& stPrjTbl, void * pszOut, int nBufferSize);

typedef void(*lpDeser)(PRJ_TABLE& stPrjTbl, const char * pszInBuffer);

void OutPutPRJTBL(PRJ_TABLE& stPrjTbl)
{
	cout << "Project index = " << stPrjTbl.nPrjIndex << endl;
	for (int nIndex = 0; nIndex < sizeof(stPrjTbl.stPrj) / sizeof(PROJECT_INFO);nIndex++)
	{
		cout << "Project id =" << stPrjTbl.stPrj[nIndex].ulPrjID << endl
			<< "Project version =" << stPrjTbl.stPrj[nIndex].dVersion << endl
			<< "Project name =" << stPrjTbl.stPrj[nIndex].szPrjName << endl;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	char bytes[1024];
	HINSTANCE hDll;//��� 
	lpSer Serialize;//���л�����ָ�� 
	lpDeser Deserialize;//�����л�����ָ��
	hDll = LoadLibrary(_T("SerializeDll.dll"));//��̬����DLLģ���� 
	if (hDll)
	{
		PRJ_TABLE stPrjTbl = {0};
		stPrjTbl.nPrjIndex = 1;
		stPrjTbl.nPrjIndex = 1;
		stPrjTbl.stPrj[0].ulPrjID = 1;
		stPrjTbl.stPrj[0].dVersion = 10.1;
		//	stPrjTbl.stPrj[0].szPrjName = "Prj1";

		stPrjTbl.stPrj[1].ulPrjID = 2;
		stPrjTbl.stPrj[1].dVersion = 10.2;
		//	stPrjTbl.stPrj[1].szPrjName = "Prj2";
		//�Խṹ��������л�
		Serialize = (lpSer)GetProcAddress(hDll, "Serialize");//�õ����л������ĵ�ַ
		if (Serialize)
		{
			Serialize(stPrjTbl, bytes, sizeof(bytes));
		}

		//�����л������ݽ��з����л�
		PRJ_TABLE stOut;
		Deserialize = (lpDeser)GetProcAddress(hDll, "Deserialize");//�õ������л������ĵ�ַ
		if (Deserialize)
		{
			Deserialize(stOut,bytes);

			OutPutPRJTBL(stOut);
		}
	}
	return 0;
}

