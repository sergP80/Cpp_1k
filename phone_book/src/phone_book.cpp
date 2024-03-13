#include "phone_book.h"
#include <algorithm>

namespace phone_book
{
	PhoneBook& PhoneBook::add(const PhoneEntry& entry)
	{
		entries_.push_back(entry);

		return *this;
	}

	void PhoneBook::remove(const PhoneEntry& entry)
	{}

	PhoneEntry PhoneBook::find_by(const std::string& term)
	{
		auto result = std::find_if(entries_.cbegin(), entries_.cend(), [&](const auto& pe) {
			return pe.is_match(term);
			});

		if (result == entries_.cend())
		{
			throw xPhoneEntryNotFound();
		}

		return *result;
	}
}