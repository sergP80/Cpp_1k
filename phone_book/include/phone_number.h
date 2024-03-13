#pragma once

#include <iostream>
#include <string>

namespace phone_book
{

	class PhoneNumber
	{
	private:
		std::string number_;
	public:
		PhoneNumber() = default;

		explicit PhoneNumber(const std::string& number)
			: number_(number)
		{}

		operator const std::string& () const
		{
			return number_;
		}

		const std::string& value() const
		{
			return number_;
		}

		bool is_match(const std::string& term) const
		{
			return number_.find(term) != std::string::npos;
		}
	};

}