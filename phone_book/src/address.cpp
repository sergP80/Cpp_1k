#include "address.h"

namespace phone_book {

	Address::Address(const std::string & country, const std::string & city, const std::string & street, const std::string& building, const std::string& zip)
		: country_(country)
		, city_(city)
		, street_(street_)
		, building_(building)
		, zip_(zip)
	{}

	bool Address::is_match(const std::string& term) const
	{
		return country_.find(term) != std::string::npos;
	}

}