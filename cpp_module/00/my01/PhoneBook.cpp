#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	currIdx = 0;
}

void	PhoneBook::addContact() {
	
}

void	PhoneBook::showContact() {
	std::cout << std::setw(43) << std::setfill('=') << "=" << std::endl;
	std::cout << std::setfill(' ');
	
}

void	PhoneBook::searchContact() {
	
	int idx;

	showContact();

	while (1)
	{
		std::cin >> idx;
		if (std::cin.fail() == false) {
			if (idx >= 1 && idx <= std::min(currIdx, 8))
				break ;
		}
		else
			std::cin.clear();
		std::cout << "index should be 1 ~ " << std::min(currIdx, 8) << std::endl;
	}
	std::cout << std::endl;
	contact[idx - 1].showInfo();
	std::cout << std::endl;
}

void	PhoneBook::exitContact() {

}

void	PhoneBook::shortedString(std::string str) {

}

PhoneBook::~PhoneBook() {

}
