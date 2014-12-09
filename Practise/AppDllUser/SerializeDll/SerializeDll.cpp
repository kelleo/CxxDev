// SerializeDll.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "structs.h"
#include "boost\archive\text_oarchive.hpp"
#include "boost\archive\text_iarchive.hpp"
#include <sstream>

extern "C" SERIALIZE_DLL_API void Serialize(PRJ_TABLE& stPrjTbl,void * pszOut,int nBufferSize)
{
	if ( pszOut )
	{
		std::ostringstream oss;
		boost::archive::text_oarchive oa(oss);
		oa & stPrjTbl;

		size_t len = oss.str().length();
		if ( len < (size_t)nBufferSize)
		{
			memcpy_s(pszOut, nBufferSize, oss.str().c_str(), oss.str().length());
		}
	}
}

extern "C" SERIALIZE_DLL_API void Deserialize(PRJ_TABLE& stPrjTbl,const char * pszInBuffer)
{
	if (pszInBuffer)
	{
		std::istringstream iss(pszInBuffer);
		boost::archive::text_iarchive oa(iss);
		oa & stPrjTbl;
	}
}
