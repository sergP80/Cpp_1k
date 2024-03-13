#include "phone_book.h"
#include <algorithm>

namespace phone_book
{
	PhoneBook& PhoneBook::add(const PhoneEntry& entry)
	{
		entries_.push_back(entry);

		return *this;
	}

	PhoneBook& PhoneBook::remove(const PhoneEntry& entry)
	{
		auto found = std::remove(entries_.begin(), entries_.end(), entry);

		if (found != entries_.end())
		{
			entries_.erase(found);
		}

		return *this;
	}

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

	void PhoneBook::show_operations(std::ostream& os) const
	{
		os << "\tView [V]\n";
		os << "\tDelete [D]\n";
	}

	void PhoneBook::select_operations(std::istream& is, std::ostream& os, const PhoneEntry& pe)
	{
		char op;

		os << "Select operation: ";
		
		is >> op;

		is.ignore(1, '\n');

		switch (op)
		{
		case 'V':
			os << pe << std::endl;
			break;
		case 'D':
			remove(pe);
			break;
		}
	}
}