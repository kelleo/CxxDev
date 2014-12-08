// SerializationExample.cpp : 定义控制台应用程序的入口点。
//	序列化的实例，boost的序列化可以序列化为文本，二进制和xml等，此例子以binary为例。
//	编写代码过程中发现，如果使用二进制，序列化后以string输出，并写入文件，但在读入数据的时候，再反序列化会有问题。
//	xml和text格式的序列化有点问题，text时，直接编译有问题，xml时，也有编译问题。

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

