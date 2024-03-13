#include "phone_entry.h"

namespace book_phone
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
}