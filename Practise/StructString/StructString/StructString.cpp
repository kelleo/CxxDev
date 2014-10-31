// StructString.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

typedef struct {
    string strNameA;
    int nNumA;
} ST_A;


typedef struct {
    ST_A stA;
    string strNameB;
    int nNumB;
} ST_B;

typedef struct {
    ST_B stB;
    string strNameC;
    int nNumC;
} ST_C;

int _tmain(int argc, _TCHAR* argv[])
{
    ST_A stA,stA1;
    stA.strNameA = "This is a name of struct ST_A";
    cout << "sizeof(stA) = " << sizeof(stA) << endl
        << "sizeof(ST_A) = " << sizeof(ST_A) << endl;
    cout << "sizeof(stA1) = " << sizeof(stA1) << endl
        << "sizeof(ST_A) = " << sizeof(ST_A) << endl;

    //sizeof()�������string��Ա�Ľṹ��ʱ���������ʵ�ʵĴ�С�����۽ṹ���string��Ա��ֵ�ж����ֽڣ�
    //sizeof������Ľ�����ǹ̶��ģ���������Ϊ��ֵ�����ֽڵ��ַ������ı䡣64λwindowsϵͳ�¼�����Ĺ̶������28�ֽڡ�
    //Ҫ���string�ַ���ʵ�ʵĳ��ȣ�������string��length()��Ա������ȡ�á�
    stA1.strNameA = "This is a name of struct ST_A1";
    cout << "after assign value to stA1 ,the sizeof(stA1) = " << sizeof(stA1) << endl
        << "The actual length of the stA1 is"<<endl<<" stA1.strNameA.length()(" 
        << stA1.strNameA.length() <<")+sizeof(stA1.nNumA)("<<sizeof(stA1.nNumA)<<") = "
        << stA1.strNameA.length() + sizeof(stA1.nNumA) << endl;
    //ֱ�Ӽ���sizeof(string)��28�ֽ�
    cout << "sizeof(string) = " << sizeof(string) << endl;

    ST_B stB;
    stB.stA = stA;
    stB.strNameB = "This is a name of struct ST_B";
    cout << "sizeof(stB) = " << sizeof(stB) << endl
        << "sizeof(ST_B) = " << sizeof(ST_B) << endl;

    ST_C stC;
    stC.stB = stB;
    stC.strNameC = "This is a name of struct ST_C";
    cout << "sizeof(stC) = " << sizeof(stC) << endl
        << "sizeof(ST_C) = " << sizeof(ST_C) << endl;

    char * pBuff = (char*)&stC;
    ST_C stBuff = *(ST_C*)pBuff;
    //string�����ÿ����ڴ�ķ�ʽȡֵ�����ƻ�string�б�����ַ�������Ϣ
    //memcpy_s(&stBuff,sizeof(stBuff),&stC,sizeof(stC));

    cout << "stBuff.strNameC = " << stBuff.strNameC << endl
        << "stBuff.stB.strNameB = " << stBuff.stB.strNameB << endl
        << "stBuff.stB.stA.strNameA = " << stBuff.stB.stA.strNameA << endl;

    getchar();

    return 0;
}

