#ifndef __CONTACT_H__
#define __CONTACT_H__

#include <string>
#include <iostream>
#include <iomanip>

class Contact
{
private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

public:
	Contact();
	std::string GetFirstName() const;
	std::string GetLastName() const;
	std::string GetNickname() const;
	std::string GetPhoneNumber() const;
	std::string GetDarkestSecret() const;
	void SetFirstName(std::string str);
	void SetLastName(std::string str);
	void SetNickname(std::string str);
	void SetPhoneNumber(std::string str);
	void SetDarkestSecret(std::string str);
	void ShowInfo();
	~Contact();
};

#endif