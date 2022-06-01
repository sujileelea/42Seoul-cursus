/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:14:23 by sujilee           #+#    #+#             */
/*   Updated: 2022/06/01 15:14:24 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BUREAUCRAT_H__
#define __BUREAUCRAT_H__

#include <string>
#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat {
private:
	const std::string _name;
	int _grade;

	static const int highestGrade = 1;
	static const int lowestGrade = 150;

public:
	const std::string getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();
	void signForm(Form& form) const;
	void executeForm(const Form& form) const;

	class GradeTooHighException: public std::exception {
	public:
		const char* what(void) const throw();
	};

	class GradeTooLowException: public std::exception {
	public:
		const char* what(void) const throw();
	};

	Bureaucrat();
	Bureaucrat(const std::string name, const int& grade);
	Bureaucrat(const Bureaucrat& copy);
	Bureaucrat& operator=(const Bureaucrat& origin);
	~Bureaucrat();
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat &ref);

#endif