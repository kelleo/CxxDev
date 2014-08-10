// Inheritance.cpp : 定义控制台应用程序的入口点。
//本代码主要回顾C++的特性继承、封装、多态中的继承特性

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
	//指针和引用，只认new的对象类型，不论接收的指针和引用是父类还是子类的指针和引用，函数都是调用new的类型的成员函数。
	A *pa = new B;
	A &a = *pa;

	pa->What();
	a.What();

	pa->How();
	a.How();

	cout << "Another situation:" << endl;
	
	//1、调用函数时，传递参数非B类型的对象，但会调用B的带参构造函数。
	//2、函数返回时，会调用拷贝构造函数构造出匿名对象赋值给对象t1，其实就相当于 B t1(func(5))。
	//3、形参作为局部变量，出了作用域会调用析构函数。
	cout <<"func called:"<< endl;
	B t1 = func(5);

	//1、形参t1传递时，调用拷贝构造函数。
	//2、函数返回时，调用拷贝构造函数，构造出匿名对象赋值给t2。
	//3、局部变量生命周期结束，调用析构函数。
	cout << "func2 called:" << endl;
	B t2 = func(t1);

	cout <<"new a pointer of class B :"<< endl;

	//指针不调用构造函数和析构函数。
	B *pt3 = &t2;

	return 0;
	//t1生命周期结束，调用析构函数。
	//t2生命周期结束，调用析构函数。
}

