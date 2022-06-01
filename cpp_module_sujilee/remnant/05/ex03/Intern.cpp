/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 10:49:25 by sujilee           #+#    #+#             */
/*   Updated: 2022/05/11 10:49:35 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Form*	Intern::makeForm(std::string name, std::string target) {
	std::string		forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	std::string*	temp = std::find(forms, forms + 3, name);
	int				idx = std::distance(forms, temp);

	switch (idx)
	{
		case 0:
			std::cout << "Intern creates <" << forms[0] << ">" << std::endl;
			return (new ShrubberyCreationForm(target));
		case 1:
			std::cout << "Intern creates <" <<  forms[1] << ">" << std::endl;
			return (new RobotomyRequestForm(target));
		case 2:
			std::cout << "Intern creates <" <<  forms[2] << ">" << std::endl;
			return (new PresidentialPardonForm(target));
		default:
			std::cout << "Invalid form name!" << std::endl;
			return NULL;
	}
}