#include "stdafx.h"
#include "UserInfo.h"


CUserInfo::CUserInfo()
{
	m_nID = 0;
}


CUserInfo::~CUserInfo()
{
}

void CUserInfo::SetUserName(const string& sUsername)
{
	m_sUserName = sUsername;
}

void CUserInfo::SetPassword(const string& sPassword)
{
	m_sPassword = sPassword;
}

void CUserInfo::SetAliasName(const string& sAliasName)
{
	m_sAliasName = sAliasName;
}

const string CUserInfo::GetUsername()
{
	return m_sUserName;
}

const string CUserInfo::GetPassword()
{
	return m_sPassword;
}

const string CUserInfo::GetAliasName()
{
	return m_sAliasName;
}

const int CUserInfo::GetUserID()
{
	return m_nID;
}

void CUserInfo::PrtInfo()
{
	cout << "User info:" << endl
		<< "username:" << m_sUserName << endl
		<< "password:" << m_sPassword << endl;
}

