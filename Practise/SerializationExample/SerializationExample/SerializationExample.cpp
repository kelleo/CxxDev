// SerializationExample.cpp : �������̨Ӧ�ó������ڵ㡣
//	���л���ʵ����boost�����л��������л�Ϊ�ı��������ƺ�xml�ȣ���������binaryΪ����
//	��д��������з��֣����ʹ�ö����ƣ����л�����string�������д���ļ������ڶ������ݵ�ʱ���ٷ����л��������⡣
//	xml��text��ʽ�����л��е����⣬textʱ��ֱ�ӱ��������⣬xmlʱ��Ҳ�б������⡣

#include "stdafx.h"
#include "UserInfo.h"
#include "include.h"

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	CUserInfo cUser;
	cUser.SetUserName("admin");
	cUser.SetPassword("admin");

	cout << "Serialize object to a binary buffer:" << endl;
	cout << "Before serialization, the data is :" << endl;
	cUser.PrtInfo();

	string sContent = Serialize2Binary(cUser);

	cout << "Serialized content:" << endl
		<< sContent << endl;

	CUserInfo user;
	UnserializeFromBinary(user, sContent);

	cout << "After unserialization, the data is :" << endl;
	user.PrtInfo();

	cout << "Serialize object to a text buffer:" << endl;
	cout << "Before serialization, the data is :" << endl;
	cUser.PrtInfo();
	sContent = Serialize2Text(cUser);
	cout << "Serialized content:" << endl
		<< sContent << endl;
	UnserializeFromText(user, sContent);
	cout << "After unserialization, the data is :" << endl;
	user.PrtInfo();

	cout << "Serialize object to a xml buffer:" << endl;
	cout << "Before serialization, the data is :" << endl;
	cUser.PrtInfo();
	sContent = Serialize2Xml(cUser);
	cout << "Serialized content:" << endl
		<< sContent << endl;
	UnserializeFromXml(user, sContent);
	cout << "After unserialization, the data is :" << endl;
	user.PrtInfo();
	return 0;
}

