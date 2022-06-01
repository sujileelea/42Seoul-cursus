#include "Contact.hpp"

std::string Contact::GetFirstName() const
{
	return firstName;
}

std::string Contact::GetLastName() const
{
	return lastName;
}

std::string Contact::GetNickname() const
{
	return nickname;
}

std::string Contact::GetPhoneNumber() const
{
	return phoneNumber;
}

std::string Contact::GetDarkestSecret() const
{
	return darkestSecret;
}

void Contact::SetFirstName(std::string str)
{
	firstName = str;
}

void Contact::SetLastName(std::string str)
{
	lastName = str;
}

void Contact::SetNickname(std::string str)
{
	nickname = str;
}

void Contact::SetPhoneNumber(std::string str)
{
	phoneNumber = str;
}

void Contact::SetDarkestSecret(std::string str)
{
	darkestSecret = str;
}

void Contact::ShowInfo()
{
	std::cout << std::setw(17) << "first name: " << GetFirstName() << std::endl;
	std::cout << std::setw(17) << "last name: " << GetLastName() << std::endl;
	std::cout << std::setw(17) << "nickname: " << GetNickname() << std::endl;
	std::cout << std::setw(17) << "phone number: " << GetPhoneNumber() << std::endl;
	std::cout << std::setw(17) << "darkest secret: " << GetDarkestSecret() << std::endl;
}

Contact::Contact() {}

Contact::~Contact() {}