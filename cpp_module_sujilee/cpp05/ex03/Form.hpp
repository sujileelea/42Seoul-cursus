/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:14:28 by sujilee           #+#    #+#             */
/*   Updated: 2022/06/01 15:14:29 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FORM_H__
#define __FORM_H__

#include "Bureaucrat.hpp"
#include <iomanip>

class Bureaucrat;

class Form {
private:
	std::string _name;
	bool _isSigned;
	int _gradeForSign;
	int _gradeForExec;

	static const int highestGrade = 1;
	static const int lowestGrade = 150;

public:
	std::string getName() const;
	bool getIsSigned() const;
	int getGradeForSign() const;
	int getGradeForExec() const;

	void beSigned(const Bureaucrat& crat);
	virtual void execute(const Bureaucrat& executor) const = 0;
	void isExecutable(const Bureaucrat& executor) const;

	class GradeTooHighException: public std::exception {
	public:
		const char* what() const throw();
	};

	class GradeTooLowException: public std::exception {
	public:
		const char* what() const throw();
	};

	class CantExecute: public std::exception {
	public:
		const char* what() const throw();
	};

	Form();
	Form(const std::string name, const int forSign, const int forExec);
	Form(const Form& copy);
	Form& operator=(const Form& origin);
	virtual ~Form();
};

std::ostream& operator<<(std::ostream& out, const Form &ref);

#endif