/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:14:51 by sujilee           #+#    #+#             */
/*   Updated: 2022/06/01 15:14:52 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

const std::string& RobotomyRequestForm::getTarget() const {
	return _target;
}

void RobotomyRequestForm::setTarget(std::string& target) {
	_target = target;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	this->isExecutable(executor);
	std::cout << "* unbearable drilling noises *" << std::endl;
	if (rand() % 2)
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else 
		std::cout << _target << " is not completed" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(): Form("Robotomy", 72, 45), _target("") {
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target): Form("Robotomy", 72, 45), _target(target) {
	std::cout << "RobotomyRequestForm constructor with target called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy): Form(copy) {
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
	*this = copy;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& origin) {
	std::cout << "RobotomyRequestForm assignation operator called" << std::endl;
	if (this != &origin) {
		Form::operator=(origin);
		this->_target = origin.getTarget();
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}
