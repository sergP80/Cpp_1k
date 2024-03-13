#include "phone_entry.h"

namespace phone_book
{
	PhoneEntry::PhoneEntry(const std::string& number, const std::string& name)
		: phone_number_(number)
		, name_(name)
		, address_(Address())
	{}

	PhoneEntry::PhoneEntry(const std::string& number, const std::string& name, const Address& address)
		: phone_number_(number)
		, name_(name)
		, address_(address)
	{}

	PhoneEntry::PhoneEntry(const PhoneNumber& number, const std::string & name, const Address & address)
		: phone_number_(number)
		, name_(name)
		, address_(address)
	{}

	bool PhoneEntry::is_match(const std::string& term) const
	{
		return name_.find(term) != std::string::npos 
			|| phone_number_.is_match(term)
			|| address_.is_match(term);
	}
}