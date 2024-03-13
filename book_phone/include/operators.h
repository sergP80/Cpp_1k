#pragma once

#include <iostream>
#include "phone_number.h"
#include "phone_entry.h"

namespace book_phone
{

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