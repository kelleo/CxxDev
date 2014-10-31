// StructString.cpp : 定义控制台应用程序的入口点。
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

    //sizeof()计算包含string成员的结构体时，结果不是实际的大小，不论结构体的string成员赋值有多少字节，
    //sizeof计算出的结果总是固定的，并不会因为赋值多少字节的字符串而改变。64位windows系统下计算出的固定结果是28字节。
    //要获得string字符串实际的长度，必须用string的length()成员函数来取得。
    stA1.strNameA = "This is a name of struct ST_A1";
    cout << "after assign value to stA1 ,the sizeof(stA1) = " << sizeof(stA1) << endl
        << "The actual length of the stA1 is"<<endl<<" stA1.strNameA.length()(" 
        << stA1.strNameA.length() <<")+sizeof(stA1.nNumA)("<<sizeof(stA1.nNumA)<<") = "
        << stA1.strNameA.length() + sizeof(stA1.nNumA) << endl;
    //直接计算sizeof(string)是28字节
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
    //string不能用拷贝内存的方式取值，会破坏string中保存的字符串的信息
    //memcpy_s(&stBuff,sizeof(stBuff),&stC,sizeof(stC));

    cout << "stBuff.strNameC = " << stBuff.strNameC << endl
        << "stBuff.stB.strNameB = " << stBuff.stB.strNameB << endl
        << "stBuff.stB.stA.strNameA = " << stBuff.stB.stA.strNameA << endl;

    getchar();

    return 0;
}

