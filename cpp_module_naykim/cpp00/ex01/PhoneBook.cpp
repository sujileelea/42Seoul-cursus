#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	nowIndex = 0;
}

void PhoneBook::ShowPhoneBook()
{
	std::cout << std::setw(43) << std::setfill('=') << "=" << std::endl;
	std::cout << std::setfill(' ');
	std::cout << std::setw(10) << "INDEX" << "|";
	std::cout << std::setw(10) << "FIRST NAME" << "|";
	std::cout << std::setw(10) << "LAST NAME" << "|";
	std::cout << std::setw(10) << "NICKNAME" << std::endl;
	std::cout << std::setw(43) << std::setfill('-') << "-" << std::endl;
	std::cout << std::setfill(' ');
	for (int i = 0; i < std::min(8, nowIndex); i++)
	{ 
		std::cout << std::setw(10) << i + 1 << "|"; 
		std::cout << std::setw(10) << ShortenString(contact[i].GetFirstName()) << "|";
		std::cout << std::setw(10) << ShortenString(contact[i].GetLastName()) << "|";
		std::cout << std::setw(10) << ShortenString(contact[i].GetNickname()) << std::endl;
	}
	std::cout << std::setw(43) << std::setfill('=') << "=" << std::endl;
	std::cout << std::setfill(' ');
}

void PhoneBook::AddContact()
{
	Contact tmp;
	std::string str;

	std::cout << "first name: ";
	std::cin >> str;
	tmp.SetFirstName(str);
	std::cout << "last name: ";
	std::cin >> str;
	tmp.SetLastName(str);
	std::cout << "nickname: ";
	std::cin >> str;
	tmp.SetNickname(str);
	std::cout << "phone number: ";
	std::cin >> str;
	tmp.SetPhoneNumber(str);
	std::cout << "darkest secret: ";
	std::cin >> str;
	tmp.SetDarkestSecret(str);
	contact[nowIndex % 8] = tmp;
	nowIndex++;
}

void PhoneBook::SearchIndex()
{
	int index;

	ShowPhoneBook();
	if (nowIndex == 0)
	{
		std::cout << "no contact to search in PhoneBook" << std::endl;
		return;
	}
	while (1)
	{
		std::cout << "Which index(number) do you want to search: ";
		std::cin >> index;
		if (std::cin.fail() == false)
		{
			if (index >= 1 && index <= std::min(nowIndex, 8))
				break ;
		}
		else
		{
			std::cin.clear();
			std::cin.ignore(100, '\n');
		}
		std::cout << "index should be between 1 and " << std::min(nowIndex, 8) << std::endl;
		
	}
	std::cout << std::endl;
	contact[index - 1].ShowInfo();
	std::cout << std::endl;
}

std::string PhoneBook::ShortenString(std::string str)
{
	if (str.length() >= 10)
		return str.substr(0, 9) + ".";
	else
		return str;
}

PhoneBook::~PhoneBook() {}
