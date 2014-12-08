#include "boost/archive/text_iarchive.hpp"
#include "boost/archive/text_oarchive.hpp"
#include "boost/archive/binary_iarchive.hpp"
#include "boost/archive/binary_oarchive.hpp"
#include "boost/archive/xml_iarchive.hpp"
#include "boost/archive/xml_oarchive.hpp"
#include <string>
#include <sstream>
#include <fstream>


template<typename TYPE>
const string Serialize2Binary(TYPE& instance)
{
	ostringstream oss("BoostSerialize.bin");
	boost::archive::binary_oarchive ar(oss);
	ar << BOOST_SERIALIZATION_NVP(instance);
	return oss.str();
}

template<typename TYPE>
void UnserializeFromBinary(TYPE& instance,const string& content)
{
	istringstream iss(content);
	boost::archive::binary_iarchive ia(iss);
	ia >> BOOST_SERIALIZATION_NVP(instance);
}

template<typename TYPE>
const string Serialize2Text(TYPE& instance)
{
	ostringstream oss;
	boost::archive::text_oarchive ar(oss);
	ar << BOOST_SERIALIZATION_NVP(instance);
	return oss.str();
}

template<typename TYPE>
void UnserializeFromText(TYPE& instance,const string& content)
{
	istringstream iss(content);
	boost::archive::text_iarchive ia(iss);
	ia >> BOOST_SERIALIZATION_NVP(instance);
}

template<typename TYPE>
const string Serialize2Xml(TYPE& instance)
{
	ostringstream oss;
	boost::archive::xml_oarchive ar(oss, boost::archive::no_header);
	ar << BOOST_SERIALIZATION_NVP(instance);
	return oss.str();
}

template<typename TYPE>
void UnserializeFromXml(TYPE& instance,const string& content)
{
	istringstream iss(content);
	boost::archive::xml_iarchive ia(iss,boost::archive::no_header);
	ia >> BOOST_SERIALIZATION_NVP(instance);
}