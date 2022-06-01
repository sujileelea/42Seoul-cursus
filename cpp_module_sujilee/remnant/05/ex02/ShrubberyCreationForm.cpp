/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 10:13:22 by sujilee           #+#    #+#             */
/*   Updated: 2022/05/11 10:41:05 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("Form", 145, 137), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& original) {
	Form::operator=(original);
	_target = original._target;
	return *this;
}

void	ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
	if (getSign() == false)
		throw ExecutetException();
	else if (getExecuteGrade() < executor.getGrade())
		throw GradeTooLowException();
	else
	{
		std::ofstream newFile(_target + "_shrubbery");
		if (newFile.is_open())
		{
			newFile << SHRUBBERY;
			newFile.close();
		}
		else
			std::cout << "open error!" << std::endl;
	}
}