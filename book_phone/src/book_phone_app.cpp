
#include "book_phone.h"

using namespace std;

int main()
{
	book_phone::PhoneNumber number1 = "+380938894125";

	cout << "Phone number 1" << endl;
	cout << number1 << endl;

	book_phone::Address address{ "Ukraine", "Mykolaiv", "68 Desantnikov", "22", "54022" };

	cout << address << endl;

	address.zip("54030");

	cout << address << endl;

	book_phone::PhoneEntry phone_entry{ number1, "Sergii Puzyrov", address };

	cout << phone_entry << endl;

	return 0;
}
