/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:16:49 by sujilee           #+#    #+#             */
/*   Updated: 2022/03/29 14:50:01 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

PhoneBook::PhoneBook() {
	currIdx = 0;
}

void	PhoneBook::ShowPhoneBook() {	
	//setfill("지정자") : 출력되는 모든 공백을 앞으로 지정자로 대체한다
	std::cout << std::setw(43) << std::setfill('=') << "=" << std::endl;
	//다시 공백으로 초기화
	std::cout << std::setfill(' ');

	std::cout << std::setw(10) << "INDEX" << "|";
	std::cout << std::setw(10) << "FIRST NAME" << "|";
	std::cout << std::setw(10) << "LAST NAME" << "|";
	std::cout << std::setw(10) << "NICKNAME" << std::endl;

	std::cout << std::setw(43) << std::setfill('=') << "=" << std::endl;
	std::cout << std::setfill(' ');

	for (int i = 0; i < std::min(8, currIdx); i++) {
		std::cout << std::setw(10) << i + 1 << "|";
		std::cout << std::setw(10) << ShortenString(contact[i].GetFirstName()) << "|";
		std::cout << std::setw(10) << ShortenString(contact[i].GetLastName()) << "|";
		std::cout << std::setw(10) << ShortenString(contact[i].GetNickName()) << std::endl;
	}

	std::cout << std::setw(43) << std::setfill('-') << "-" << std::endl;
	std::cout << std::setfill(' ');
 }

void	PhoneBook::AddContact() {
	Contact newest;
	std::string input;

	std::cout << "First Name: ";
	std::cin >> input;
	newest.SetFirstName(input);

	std::cout << "Last Name: ";
	std::cin >> input;
	newest.SetLastName(input);

	std::cout << "Nickname: ";
	std::cin >> input;
	newest.SetNickName(input);

	std::cout << "Phone Number: ";
	std::cin >> input;
	newest.SetPhoneNumber(input);

	std::cout << "Darkest Secret...: ";
	std::cin >> input;
	newest.SetDarkestSecret(input);

	contact[currIdx % 8] = newest;
	currIdx++;
}

void	PhoneBook::SearchIndex() {
	int idx;

	ShowPhoneBook();
	if (currIdx == 0) {
		std::cout << "There is no Contact exist in PhoneBook" << std::endl;
		return ;
	}
	while (1) {
		std::cout << "Input index of Contact you wanna search :";
		std::cin >> idx;
		
		//사용자가 올바르게 입력했을 경우
		if (std::cin.fail() == false) {
			if (idx >= 1 && idx <=std::min(currIdx, 8))
				break ;
		}
		//그게 아니라면 clear하고 ignore해서 후에 cin기능이 정상작동하게 해준다.
		else {
			std::cin.clear();
			std::cin.ignore(100, '\n');
		}
		std::cout << "index should be between 1 ~ " << std::min(currIdx, 8) << std::endl;
	}
	std::cout << std::endl;
	contact[idx - 1].ShowInfo();
	std::cout << std::endl;
}

std::string PhoneBook::ShortenString(std::string str) {
	if (str.length() >= 10)
		return str.substr(0, 9) + ".";
	else
		return str;
}

//소멸자 : 
PhoneBook::~PhoneBook() {}