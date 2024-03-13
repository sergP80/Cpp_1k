#pragma once

#include <iostream>
#include <string>

namespace book_phone
{

	class PhoneNumber
	{
	private:
		std::string number_;
	public:
		PhoneNumber(const std::string& number)
			: number_(number)
		{}

		const std::string& value() const
		{
			return number_;
		}

		operator const std::string&() const
		{
			return number_;
		}
	};

}