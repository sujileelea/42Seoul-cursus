/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 09:52:16 by sujilee           #+#    #+#             */
/*   Updated: 2022/04/01 10:52:52 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}

std::string Contact::GetFirstName() const {
	return firstName;
}

std::string Contact::GetLastName() const {
	return lastName;
}

std::string Contact::GetNickName() const {
	return nickName;
}

std::string Contact::GetPhoneNumber() const {
	return phoneNumber;
}

std::string Contact::GetDarkestSecret() const {
	return darkestSecret;
}

void	Contact::SetFirstName(std::string str) {
	firstName = str;
}

void	Contact::SetLastName(std::string str) {
	lastName = str;
}

void	Contact::SetNickName(std::string str) {
	nickName = str;
}

void	Contact::SetPhoneNumber(std::string str) {
	phoneNumber = str;
}

void	Contact::SetDarkestSecret(std::string str) {
	darkestSecret = str;
}

void	Contact::ShowInfo() {
	std::cout << std::setw(17) << "First Name: " << GetFirstName() << std::endl;
	std::cout << std::setw(17) << "Last Name: " << GetLastName() << std::endl;
	std::cout << std::setw(17) << "Nickname: " << GetNickName() << std::endl;
	std::cout << std::setw(17) << "Phonenumber: " << GetPhoneNumber() << std::endl;
	std::cout << std::setw(17) << "Dartkest Secret...: " << GetDarkestSecret() << std::endl;
}


Contact::~Contact() {}
