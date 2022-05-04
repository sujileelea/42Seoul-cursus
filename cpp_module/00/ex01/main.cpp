/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:28:20 by sujilee           #+#    #+#             */
/*   Updated: 2022/05/04 11:56:49 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
 
int		main(void) {
	PhoneBook phoneBook;
	std::string input;

	while (1) {
		std::cout << "input ADD or SEARCH or EXIT : ";
		std::cin >> input;
		
		if (input.compare("EXIT") == 0) {
			std::cout << "Terminate Program" << std::endl;
			break ;
		}
		else if (input.compare("ADD") == 0)
			phoneBook.AddContact();
		else if (input.compare("SEARCH") == 0)
			phoneBook.SearchIndex();
		else
			std::cout << "Wrong input !" << std::endl;
	}
	return (0);
}