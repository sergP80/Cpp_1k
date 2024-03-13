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

	bool operator==(const Address& lhs, const Address& rhs)
	{
		return lhs.country() == rhs.country()
			&& lhs.city() == rhs.city()
			&& lhs.street() == rhs.street()
			&& lhs.building() == rhs.building()
			&& lhs.zip() == rhs.zip();
	}

	bool operator==(const PhoneNumber& lhs, const PhoneNumber& rhs)
	{
		return lhs.value() == rhs.value();
	}

	bool operator==(const PhoneEntry& lhs, const PhoneEntry& rhs)
	{
		return lhs.name() == rhs.name()
			&& lhs.address() == rhs.address()
			&& lhs.phone_number() == rhs.phone_number();
	}
}