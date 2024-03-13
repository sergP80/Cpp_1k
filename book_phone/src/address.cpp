#include "address.h"

namespace book_phone {

	Address::Address(const std::string & country, const std::string & city, const std::string & street, const std::string& building, const std::string& zip)
		: country_(country)
		, city_(city)
		, street_(street_)
		, building_(building)
		, zip_(zip)
	{}

	std::ostream& operator<<(std::ostream& os, const Address& address)
	{
		os << "{";
		os << "Country: " << address.country_;
		os << ", City: " << address.city_;
		os << ", Street: " << address.street_;
		os << ", Building: " << address.building_;
		os << ", Zip: " << address.zip_;
		os << "}";

		return os;
	}
}