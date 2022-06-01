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

	class GradeTooHighException: public std::exception {
	public:
		const char* what() const throw();
	};

	class GradeTooLowException: public std::exception {
	public:
		const char* what() const throw();
	};

	Form();
	Form(const std::string name, const int forSign, const int forExec);
	Form(const Form& copy);
	Form& operator=(const Form& origin);
	~Form();
};

std::ostream& operator<<(std::ostream& out, const Form &ref);

#endif