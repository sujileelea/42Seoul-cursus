/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 17:08:12 by sujilee           #+#    #+#             */
/*   Updated: 2022/04/19 17:29:51 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

Karen::Karen() {}


void	Karen::debug() {
	std::cout << "DEBUG : " << "contextual information" << std::endl;
}

void	Karen::info() {
	std::cout << "INFO : " << "extensive information" << std::endl;
}

void	Karen::warning() {
	std::cout << "WARNING : " << "potential issue" << std::endl;
}

void	Karen::error() {
	std::cout << "ERROR : " << "unrecover error" << std::endl;
}

void	Karen::complain(std::string level) {
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void	(Karen::*functions[4])() = {&Karen::debug, &Karen::info, &Karen::warning, &Karen::error};

	for (int i = 0; i < 4; i++) {
		if (levels[i] == level)
			return (this->*(functions[i]))();
	}
	std::cout << "Nothing Special" << std::endl;
}





Karen::~Karen() {}