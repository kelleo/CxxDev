#pragma once
#include <string>
#include "boost\archive\text_oarchive.hpp"
using namespace std;

class CUserInfo
{
	int m_nID;
	string m_sUserName;
	string m_sPassword;
	string m_sAliasName;
public:
	CUserInfo();
	~CUserInfo();

	friend boost::serialization::access;
	template<class Archive> void serialize(Archive& ar, const unsigned int version)
	{
		ar & BOOST_SERIALIZATION_NVP(m_nID);
		ar & BOOST_SERIALIZATION_NVP(m_sUserName);
		ar & BOOST_SERIALIZATION_NVP(m_sPassword);
		ar & BOOST_SERIALIZATION_NVP(m_sAliasName);
	}

	void SetUserName(const string& sUsername);
	void SetPassword(const string& sPassword);
	void SetAliasName(const string& sAliasName);
	const string GetUsername();
	const string GetPassword();
	const string GetAliasName();
	const int GetUserID();

	void PrtInfo();
};

