#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "phone_number.h"
#include "address.h"
#include "phone_entry.h"
#include "operators.h"

namespace phone_book
{

	struct xPhoneEntryNotFound
	{};

	class PhoneBook
	{
	private:
		std::vector<PhoneEntry> entries_;
	public:
		PhoneBook() = default;

		PhoneBook& add(const PhoneEntry& entry);
		
		PhoneBook& remove(const PhoneEntry& entry);

		PhoneEntry find_by(const std::string& term);

		const std::vector<PhoneEntry> entries() const
		{
			return entries_;
		}

		void show_operations(std::ostream& os) const;
		
		void select_operations(std::istream&, std::ostream&, const PhoneEntry&);
	};
}