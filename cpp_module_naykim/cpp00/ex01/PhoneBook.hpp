#ifndef __PHONE_BOOK_H__
#define __PHONE_BOOK_H__

#include "Contact.hpp"

class PhoneBook
{
private:
	Contact contact[8];
	int	nowIndex;

public:
	PhoneBook();
	void ShowPhoneBook();
	void AddContact();
	void SearchIndex();
	std::string ShortenString(std::string str);
	~PhoneBook();
};

#endif