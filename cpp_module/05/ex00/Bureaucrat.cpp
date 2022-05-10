/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:15:54 by sujilee           #+#    #+#             */
/*   Updated: 2022/05/10 13:28:57 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name(""), _grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	if (grade < 1) 
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& original) : _name(original._name), _grade(original._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& original) {
	_grade = original._grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string	Bureaucrat::getName() const {
	return _name;
}

int	Bureaucrat::getGrade() const {
	return _grade;
}

void	Bureaucrat::upGrade(int grade) {
	if (_grade - grade <= 0)
		throw GradeTooHighException();
	_grade -= grade;
}

void	Bureaucrat::downGrade(int grade) {
	if (_grade + grade > 150)
		throw GradeTooLowException();
	_grade += grade;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low!";
}

std::ostream& operator<<(std::ostream& o, const Bureaucrat& original) {
	o << "<" << original.getName() << ">, Bureaucrat grade <" << original.getGrade() << ">" <<std::endl;
	return o;
}