#pragma once

#include <iostream>
#include <string>
#include "phone_number.h"
#include "address.h"

namespace book_phone
{

	class PhoneEntry
	{
	private:
		PhoneNumber phone_number_;
		
		std::string name_;

		Address address_;
	public:
		PhoneEntry()
			: phone_number_("")
		{}

		PhoneEntry(const std::string& number, const std::string& name);

		PhoneEntry(const std::string& number, const std::string& name,const Address& address);
		
		PhoneEntry(const PhoneNumber& number, const std::string& name,const Address& address);

		const PhoneNumber& phone_number() const
		{
			return phone_number_;
		}
		
		void phone_number(const PhoneNumber& phone_number)
		{
			phone_number_ = phone_number;
		}
		
		const std::string& name() const
		{
			return name_;
		}
		
		void name(const std::string& name)
		{
			name_ = name;
		}

		const Address& address() const
		{
			return address_;
		}

		void address(const Address& address)
		{
			address_ = address;
		}

	};
}