/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 09:18:31 by sujilee           #+#    #+#             */
/*   Updated: 2022/05/11 09:28:14 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name(""), _isSigned(false), _signGrade(50), _executeGrade(20) {}

Form::Form(const Form& original) : _name(original._name), _isSigned(false), _signGrade(original._signGrade), _executeGrade(original._executeGrade) {}

Form::Form(std::string name, int signGrade, int executeGrade) : _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade) {
	if (_signGrade < 1 || _executeGrade < 1)
		throw GradeTooHighException();
	else if (_signGrade > 150 || _executeGrade > 150)
		throw GradeTooLowException();
}

Form& Form::operator=(const Form& original) {
	_isSigned = original._isSigned;
	return *this;
}

Form::~Form() {}


std::string	Form::getName(void) const {
	return _name;
}

bool	Form::getSign(void) const {
	return _isSigned;
}

int	Form::getSignGrade(void) const {
	return _signGrade;
}

int	Form::getExecuteGrade(void) const {
	return _executeGrade;
}

bool Form::beSigned(const Bureaucrat& crat) {
	if (crat.getGrade() <= _signGrade) {
		_isSigned = true;
	} else {
		_isSigned = false;
	}
	
	return _isSigned;
}

const char*	Form::GradeTooHighException::what() const throw() {
	return "Grade too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade too low!";
}

std::ostream&	operator<<(std::ostream& out, const Form& ref)
{
	out << "<" << ref.getName() << ">, form sign grade <" << ref.getSignGrade() << "> form execute grade <"
	<< ref.getExecuteGrade() << ">" << std::endl;
	return out;
}