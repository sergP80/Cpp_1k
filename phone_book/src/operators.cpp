#include "operators.h"

namespace phone_book
{
	std::ostream& operator<<(std::ostream& os, const Address& address)
	{
		os << "{";
		os << "Country: " << address.country();
		os << ", City: " << address.city();
		os << ", Street: " << address.street();
		os << ", Building: " << address.building();
		os << ", Zip: " << address.zip();
		os << "}";

		return os;
	}

	std::ostream& operator<<(std::ostream& os, const PhoneNumber& phone_number)
	{
		os << phone_number.value();
		return os;
	}

	std::ostream& operator<<(std::ostream& os, const PhoneEntry& pe)
	{
		os << "{";
		os << "Phone number: " << pe.phone_number();
		os << ", Name:" << pe.name();
		os << ", Address" << pe.address();
		os << "}";

		return os;
	}
	

}