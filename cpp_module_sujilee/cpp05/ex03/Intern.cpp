/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:14:32 by sujilee           #+#    #+#             */
/*   Updated: 2022/06/01 15:14:33 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Form* Intern::makeForm(const std::string& name, const std::string& target) const {
	Form* ret = 0;
	std::string forms[3] = {"shrubbery", "robotomy", "president"};
	Form* makeforms[3] = {new ShrubberyCreationForm(target),
							new RobotomyRequestForm(target),
							new PresidentialPardonForm(target) };
	
	for (int i = 0; i < 3; i++) {
		if (name == forms[i])
			ret = makeforms[i];
		else
			delete makeforms[i];
	}
	if (ret == NULL)
		throw Intern::CantFindForm();
	std::cout << "Intern creates the right form \"" << name << "\"." << std::endl;
	return ret;
}

const char* Intern::CantFindForm::what(void) const throw() {
	return "Intern didn't find the form.";
}

Intern::Intern() {
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern& copy) {
	std::cout << "Intern copy constructor called" << std::endl;
	*this = copy;
}

Intern& Intern::operator=(const Intern& origin) {
	std::cout << "Intern assignation operator called" << std::endl;
	if (this == &origin)
		std::cout << "same address." << std::endl;
	return (*this);
}

Intern::~Intern() {
	std::cout << "Intern destructor called" << std::endl;
}
