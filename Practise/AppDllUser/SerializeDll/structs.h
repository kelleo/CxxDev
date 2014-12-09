//////////////////////////////////////////////////////////////////////////
//	定义结构体，供dll使用
//////////////////////////////////////////////////////////////////////////

#ifndef __STRUCTS_HEADER__
#define __STRUCTS_HEADER__
using namespace std;

struct PROJECT_INFO{
	unsigned int ulPrjID;
	double dVersion;
	char szPrjName[20];
};

template<class Archive> void serialize(Archive& ar, PROJECT_INFO& stPrj, const unsigned int version)
{
	ar & stPrj.ulPrjID;
	ar & stPrj.dVersion;
	ar & stPrj.szPrjName;
}


struct PRJ_TABLE{
	int nPrjIndex;
	PROJECT_INFO stPrj[3];
};

template<class Archive> void serialize(Archive& ar, PRJ_TABLE& stPrjTbl, const unsigned int version)
{
	ar & stPrjTbl.nPrjIndex;
	ar & stPrjTbl.stPrj;
}

#endif // !__STRUCTS_HEADER__
