
#include "phone_book.h"

using namespace std;
using namespace phone_book;


int main()
{
	PhoneBook phone_book;

	phone_book
		.add(
			PhoneEntry{ "+380938894125", "Sergii Puzyrov", Address{ "Ukraine", "Mykolaiv", "68 Desantnikov", "22", "54022" } }
		)
		.add(
			PhoneEntry{ "+380967782179", "Yourii Kremer", Address{ "Ukraine", "Mykolaiv", "Velika Morska", "14", "54011" } }
	);

	std::string term;
	
	do {
		
		cout << "--------------------------------------" << endl;
		cout << phone_book.entries() << endl;
		cout << "--------------------------------------" << endl;
		cout << "Enter search (Q to exit): ";

		getline(cin, term, '\n');

		if (term == "Q")
		{
			break;
		}

		try
		{
			auto result = phone_book.find_by(term);

			char operation;

			cout << "Entry found. What woud you like to do?" << endl;

			phone_book.show_operations(cout);

			phone_book.select_operations(cin, cout, result);
		}
		catch (xPhoneEntryNotFound e)
		{
			cout << "Sorry! Entry with term " << term + " was not found" << endl;
		}
		catch (const string& e)
		{
			cout << e << endl;
		}
		
	} while (true);
	
	return 0;
}
