/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 13:30:52 by sujilee           #+#    #+#             */
/*   Updated: 2022/04/19 13:37:54 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int		main(void) {
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string; //stringREF는 string의 또다른 이름이다!

	std::cout << "address of string : " << &string << std::endl;
	std::cout << "address stringPTR is holding : " << stringPTR << std::endl;
	std::cout << "address stringREF is holding : " << &stringREF << std::endl;

	std::cout << "string : " << string << std::endl;
	std::cout << "stringPRT : " << *stringPTR << std::endl;
	std::cout << "stringREF : " << stringREF << std::endl;

	return (0);
}
