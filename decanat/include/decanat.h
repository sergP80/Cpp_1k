// integral.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <string>
#include "contact.h"
#include "address.h"
#include "ticket.h"
#include "personal.h"

namespace decanat {

	class Group {
	private:
		int id;
		std::string name;
	};

	class Student {
	private:
		Personal& personal_;

		Group& group_;

		const Ticket& ticket_;

		Contact& contact_;

		Address& address_;

	public:
		Student(Personal& personal, Group& group, const Ticket& ticket, Contact& contact, Address& address)
			: personal_(personal)
			, group_(group)
			, ticket_(ticket)
			, contact_(contact)
			, address_(address)
		{}
	};
}