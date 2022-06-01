#include "Contact.hpp"
#include "PhoneBook.hpp"

int main()
{
	PhoneBook phoneBook;
	std::string command;

	while (1)
	{
		std::cout << "Type your command(ADD or SEARCH or EXIT) : ";
		std::cin >> command;
		if (!command.compare("ADD"))
			phoneBook.AddContact();
		else if (!command.compare("SEARCH"))
			phoneBook.SearchIndex();
		else if (!command.compare("EXIT"))
			break;
	}
	std::cout << "==Terminate the program==" << std::endl;
	return 0;
}