#pragma once

#include <iostream>
#include <vector>
#include "phone_number.h"
#include "phone_entry.h"

namespace phone_book
{
	std::ostream& operator<<(std::ostream& os, const Address& address);

	std::ostream& operator<<(std::ostream& os, const PhoneNumber& phone_number);

	std::ostream& operator<<(std::ostream& os, const PhoneEntry& pe);
	
	template<typename T>
	std::ostream& operator<<(std::ostream& os, const std::vector<T>& collection)
	{
		for (const auto& item : collection)
		{
			os << item << std::endl;
		}

		return os;
	}

	bool operator==(const Address&, const Address&);

	bool operator==(const PhoneNumber&, const PhoneNumber&);

	bool operator==(const PhoneEntry&, const PhoneEntry&);

}