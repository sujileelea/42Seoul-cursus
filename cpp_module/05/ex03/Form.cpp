/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 09:18:31 by sujilee           #+#    #+#             */
/*   Updated: 2022/05/11 10:39:56 by sujilee          ###   ########.fr       */
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

std::string	Form::getName() const {
	return _name;
}

bool	Form::getSign() const {
	return _isSigned;
}

int	Form::getSignGrade() const {
	return _signGrade;
}

int	Form::getExecuteGrade() const {
	return _executeGrade;
}

bool	Form::beSigned(const Bureaucrat& sign) {
	if (sign.getGrade() <= _signGrade)
		_isSigned = true;
	else
		_isSigned = false;
	return _isSigned;
}

const char*	Form::GradeTooHighException::what() const throw() {
	return "Grade too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade too low!";
}

const char*	Form::ExecutetException::what() const throw() {
	return "It's not signed!";
}

std::ostream&	operator<<(std::ostream& o, const Form& original) {
	o << "<" << original.getName() << ">, form sign grade <" << original.getSignGrade() << "> form execute grade <"
	<< original.getExecuteGrade() << ">" << std::endl;
	return o;
}