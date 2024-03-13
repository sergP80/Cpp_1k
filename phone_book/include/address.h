#pragma once

#include <iostream>
#include <string>

namespace phone_book {

	class Address {
	private:
		std::string country_;
		std::string city_;
		std::string street_;
		std::string building_;
		std::string zip_;
	public:
		Address() = default;

		Address(const std::string& country, const std::string& city, const std::string& street, const std::string& building, const std::string& zip);

		const std::string& country() const
		{
			return country_;
		}
		
		void country(const std::string& country)
		{
			country_ = country;
		}
		
		const std::string& city() const
		{
			return city_;
		}
		
		void city(const std::string& city)
		{
			city_ = city;
		}
		
		const std::string& street() const
		{
			return street_;
		}
		
		void street(const std::string& street)
		{
			street_ = street;
		}
		
		const std::string& building() const
		{
			return building_;
		}
		
		void building(const std::string& building)
		{
			building_ = building;
		}
		
		const std::string& zip() const
		{
			return zip_;
		}
		
		void zip(const std::string& zip)
		{
			zip_ = zip;
		}

		bool is_match(const std::string& term) const;
	};
}