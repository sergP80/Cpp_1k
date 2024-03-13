// integral.cpp : Defines the entry point for the application.
//

#include "decanat.h"

using namespace std;

int main()
{
	decanat::Personal personal{"John Doe", "1991/12/24"};

	decanat::Group group;
	
	decanat::Ticket ticket;
	
	decanat::Address address;

	decanat::Contact contact{ "+380967715308", "email1@gmail.com", "tme/c1" };

	decanat::Student s1{ personal, group, ticket, contact, address };

	cout << personal << endl;
	cout << contact << endl;
}
