#include "Contact.hpp"

Contact::Contact() {}


std::string Contact::getFirstName() {
	return firstName;
}

std::string Contact::getLastName() {
	return lastName;
}

std::string Contact::getNickName() {
	return  nickName;
}

std::string Contact::getPhoneNumber() {
	return phoneNumber;
}

std::string Contact::getDarkestSecret() {
	return darkestSecret;
}


void		Contact::setFirstName(std::string str) {
	firstName = str;
}

void		Contact::setLastName(std::string str) {
	lastName = str;
}

void		Contact::setNickName(std::string str) {
	nickName = str;
}

void		Contact::setPhoneNumber(std::string str) {
	phoneNumber = str;
}

void		Contact::setDarkestSecret(std::string str) {
	darkestSecret = str;
}


void		Contact::showInfo() {
	
	std::cout << "first name : " << getFirstName() << std::endl;
	std::cout << "last name : " << getLastName() << std::endl;
	std::cout << "nickname : " << getNickName() << std::endl;
	std::cout << "phone number : " << getPhoneNumber() << std::endl;
	std::cout << "darkest secret : " << getDarkestSecret() << std::endl;
}



Contact::~Contact() {}