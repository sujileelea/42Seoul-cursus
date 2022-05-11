/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotoMyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 10:10:14 by sujilee           #+#    #+#             */
/*   Updated: 2022/05/11 10:40:48 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("Form", 72, 45), _target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& original) {
	Form::operator=(original);
	_target = original._target;
	return *this;
}

void	RobotomyRequestForm::execute(Bureaucrat const& executor) const {
	if (getSign() == false)
		throw ExecutetException();
	else if (getExecuteGrade() < executor.getGrade())
		throw GradeTooLowException();
	else {
		srand((unsigned int)time(NULL));
		int	randNum= rand() % 2;
		std::cout << "Dudududududu!" << std::endl;
		if (randNum != 0)
			std::cout << "<" << _target << "> has been robotomized successfully" << std::endl;
		else
			std::cout << "<" << _target << "> failed to robotomized" << std::endl;
	}
}