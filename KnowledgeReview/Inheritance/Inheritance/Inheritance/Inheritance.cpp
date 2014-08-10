// Inheritance.cpp : �������̨Ӧ�ó������ڵ㡣
//��������Ҫ�ع�C++�����Լ̳С���װ����̬�еļ̳�����

#include "stdafx.h"
#include <iostream>

using namespace std;

class A
{
protected:
	int nData;
public:
	A() :nData(0)
	{
		//cout << "A Default constructor!data = "<<nData << endl;
	}
	A(int nNum) :nData(nNum)
	{
		//cout << "A Constructor data " << nData << endl;
	}

	virtual void What()
	{
		cout << "A What" << endl;
	}

	virtual void How()
	{
		cout << "A How" << endl;
	}

	~A()
	{
		//cout << "A Desctructored!" << endl;
	}
};


class B :public A
{
protected:
	int nData;
public:
	B() :nData(0)
	{
		cout << "B Default constructor!data = " << nData << endl;
	}
	B(int nNum) :nData(nNum)
	{
		cout << "B Constructor data " << nData << endl;
	}
	B(const B& ref)
	{
		cout << "B Copy Constructor" << endl;
	}

	virtual void What()
	{
		cout << "B What" << endl;
	}

	virtual void How()
	{
		cout << "B How" << endl;
	}

	~B()
	{
		cout << "B Desctructored!" << endl;
	}
};

B func(B b)
{
	return b;
}

B& func2(B& b)
{
	return b;
}

int _tmain(int argc, _TCHAR* argv[])
{
	//ָ������ã�ֻ��new�Ķ������ͣ����۽��յ�ָ��������Ǹ��໹�������ָ������ã��������ǵ���new�����͵ĳ�Ա������
	A *pa = new B;
	A &a = *pa;

	pa->What();
	a.What();

	pa->How();
	a.How();

	cout << "Another situation:" << endl;
	
	//1�����ú���ʱ�����ݲ�����B���͵Ķ��󣬵������B�Ĵ��ι��캯����
	//2����������ʱ������ÿ������캯���������������ֵ������t1����ʵ���൱�� B t1(func(5))��
	//3���β���Ϊ�ֲ�������������������������������
	cout <<"func called:"<< endl;
	B t1 = func(5);

	//1���β�t1����ʱ�����ÿ������캯����
	//2����������ʱ�����ÿ������캯�����������������ֵ��t2��
	//3���ֲ������������ڽ�������������������
	cout << "func2 called:" << endl;
	B t2 = func(t1);

	cout <<"new a pointer of class B :"<< endl;

	//ָ�벻���ù��캯��������������
	B *pt3 = &t2;

	return 0;
	//t1�������ڽ�������������������
	//t2�������ڽ�������������������
}

