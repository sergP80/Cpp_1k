#pragma once

#include <iostream>
#include <string>

namespace decanat {

	class Address {
	private:
		std::string country;
		std::string city;
		std::string street;
		std::string building;
		std::string zip;
	};
}