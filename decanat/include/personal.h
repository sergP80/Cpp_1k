// integral.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <string>

namespace decanat {

	class Personal {
	private:
		std::string name_;

		std::string birth_date_;

		std::string photo_url_;

	public:
		Personal() = default;

		Personal(const std::string& name, const std::string& birth_date = "", const std::string& photo_url = "")
			: name_(name)
			, birth_date_(birth_date)
			, photo_url_(photo_url)
		{}

		const std::string& name() const
		{
			return this->name_;
		}

		void name(const std::string& name)
		{
			this->name_ = name;
		}
		
		const std::string& birth_date() const
		{
			return this->birth_date_;
		}

		void birth_date(const std::string& birth_date)
		{
			this->birth_date_ = birth_date;
		}

		const std::string& photo_url() const
		{
			return this->photo_url_;
		}
		
		void photo_url(const std::string& photo_url)
		{
			this->photo_url_ = photo_url;
		}

		friend std::ostream& operator<<(std::ostream& os, const Personal& personal);
	};

	std::ostream& operator<<(std::ostream& os, const Personal& personal)
	{
		os << "Personal{";
		os << "name: " << personal.name_;

		if (!personal.birth_date_.empty())
		{
			os << ", birth date:" << personal.birth_date_;
		}

		if (!personal.photo_url_.empty())
		{
			os << ", photo url:" << personal.photo_url_;
		}
		os << "}";

		return os;
	}
}