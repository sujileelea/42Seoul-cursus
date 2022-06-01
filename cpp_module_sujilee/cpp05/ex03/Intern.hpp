/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:14:36 by sujilee           #+#    #+#             */
/*   Updated: 2022/06/01 15:14:37 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __INTERN_H__
#define __INTERN_H__

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

class Intern {
public:
	Form* makeForm(const std::string& name, const std::string& target) const;

	class CantFindForm: public std::exception {
	public:
		const char* what(void) const throw();
	};

	Intern();
	Intern(const Intern& copy);
	Intern& operator=(const Intern& origin);
	virtual ~Intern();
};

#endif