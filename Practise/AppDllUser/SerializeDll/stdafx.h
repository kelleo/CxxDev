// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             //  �� Windows ͷ�ļ����ų�����ʹ�õ���Ϣ
// Windows ͷ�ļ�: 
#include <windows.h>

#ifdef _USRDLL
#define SERIALIZE_DLL_API __declspec(dllexport)
#else 
#define SERIALIZE_DLL_API __declspec(dllimport)
#endif

// TODO:  �ڴ˴����ó�����Ҫ������ͷ�ļ�
