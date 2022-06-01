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