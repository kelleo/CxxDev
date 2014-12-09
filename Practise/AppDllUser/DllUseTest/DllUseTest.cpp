// DllUseTest.cpp : 定义控制台应用程序的入口点。
// Dll的测试工程，用于测试Dll中的函数是否可在Dll外进行调用

#include "stdafx.h"
#include "..\SerializeDll\structs.h"
#include <windows.h>
#include <iostream>

using namespace std;

//声明Dll对应的函数指针
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
	HINSTANCE hDll;//句柄 
	lpSer Serialize;//序列化函数指针 
	lpDeser Deserialize;//反序列化函数指针
	hDll = LoadLibrary(_T("SerializeDll.dll"));//动态加载DLL模块句柄 
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
		//对结构体进行序列化
		Serialize = (lpSer)GetProcAddress(hDll, "Serialize");//得到序列化函数的地址
		if (Serialize)
		{
			Serialize(stPrjTbl, bytes, sizeof(bytes));
		}

		//对序列化的内容进行反序列化
		PRJ_TABLE stOut;
		Deserialize = (lpDeser)GetProcAddress(hDll, "Deserialize");//得到反序列化函数的地址
		if (Deserialize)
		{
			Deserialize(stOut,bytes);

			OutPutPRJTBL(stOut);
		}
	}
	return 0;
}

