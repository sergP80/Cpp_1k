#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "utils.h"

namespace decanat {
	class Contact {
	private:
		std::vector<std::string> phones_;

		std::vector<std::string> emails_;

		std::string facebook_;

		std::string telegram_;

		std::string instagram_;

	public:
		Contact() = default;

		Contact(const std::string& phone, const std::string& email)
		{
			this->phones_.push_back(phone);
			this->emails_.push_back(email);
		}

		Contact(const std::string& phone, const std::string& email, const std::string& telegram)
			: Contact(phone, email)
		{
			this->telegram_ = telegram;
		}

		const std::vector<std::string>& phones() const
		{
			return this->phones_;
		}

		void add_phone(const std::string& phone)
		{
			phones_.push_back(phone);
		}

		void remove_phone(const std::string& phone)
		{
			auto found = std::remove_if(phones_.begin(), phones_.end(), [&](const std::string p) { return p == phone; });

			if (found != phones_.end()) {
				phones_.erase(found, phones_.end());
			}
		}

		const std::vector<std::string>& emails() const
		{
			return this->emails_;
		}

		void add_email(const std::string& email)
		{
			emails_.push_back(email);
		}

		const std::string& facebook() const
		{
			return this->facebook_;
		}

		void facebook(const std::string& facebook)
		{
			this->facebook_ = facebook;
		}

		const std::string& telegram() const
		{
			return this->telegram_;
		}

		void telegram(const std::string& telegram)
		{
			this->telegram_ = telegram;
		}

		const std::string& instagram() const
		{
			return this->instagram_;
		}

		void instagram(const std::string& instagram)
		{
			this->instagram_ = instagram;
		}

		const bool empty() const
		{
			return phones_.empty()
				&& emails_.empty()
				&& facebook_.empty()
				&& telegram_.empty()
				&& instagram_.empty();
		}

		friend std::ostream& operator<<(std::ostream& os, const Contact& contact);

	};

	std::ostream& operator<<(std::ostream& os, const Contact& contact)
	{
		os << "Contact{";

		if (!contact.empty())
		{ 
			if (!contact.phones_.empty())
			{
				os << "phones: " << contact.phones_;
			}
			
			if (!contact.emails_.empty())
			{
				if (!contact.phones_.empty())
				{
					os << ",";
				}
				os << "emails: " << contact.emails_;
			}
		}


		os << "}";

		return os;
	}
}