/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 10:04:43 by sujilee           #+#    #+#             */
/*   Updated: 2022/05/11 10:40:24 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("Form", 25, 5), _target(target) {}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& original) {
	Form::operator=(original);
	_target = original._target;
	return *this;
}

void	PresidentialPardonForm::execute(Bureaucrat const& executor) const {
	if (getSign() == false)
		throw ExecutetException();
	else if (getExecuteGrade() < executor.getGrade())
		throw GradeTooLowException();
	else
		std::cout << "<" << _target << "> has been pardoned by Zafod Beeblebrox." << std::endl;
}