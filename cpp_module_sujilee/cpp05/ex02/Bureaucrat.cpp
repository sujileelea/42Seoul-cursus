#include "Bureaucrat.hpp"

const std::string Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

void Bureaucrat::incrementGrade() {
	if (_grade - 1 < Bureaucrat::highestGrade)
		throw Bureaucrat::GradeTooHighException();
	--_grade;
}

void Bureaucrat::decrementGrade() {
	if (_grade + 1 > Bureaucrat::lowestGrade)
		throw Bureaucrat::GradeTooLowException();
	++_grade;
}

void Bureaucrat::signForm(Form& form) const {
	try {
		form.beSigned(*this);
		std::cout << this->getName() << " signs " << form.getName() << "." << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << this->getName() << " cannot sign " << form.getName() << ". Because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(const Form& form) const {
	try {
		form.execute(*this);
		std::cout << this->_name << " executes Form " << form.getName() << std::endl;
	}
	catch(Form::CantExecute &e) {
		std::cerr << e.what() << std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what(void) const throw() {
	return "Grade is too high.";
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw() {
	return "Grade is too low.";
}

Bureaucrat::Bureaucrat(): _name(""), _grade(Bureaucrat::lowestGrade) {
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, const int& grade): _name(name), _grade(grade) {
	std::cout << "Bureaucrat constructor with name \"" << name << "\" called" << std::endl;
	if (_grade < Bureaucrat::highestGrade)
		throw Bureaucrat::GradeTooHighException();
	if (_grade > Bureaucrat::lowestGrade)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) {
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = copy;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& origin) {
	std::cout << "Bureaucrat assignation operator called" << std::endl;
	if (this != &origin) {
		*(const_cast<std::string*>(&_name)) = origin.getName();
		_grade = origin.getGrade();
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat " << _name << " destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat &ref) {
	out << "<" << ref.getName() << ">, bureaucrat grade is <" << ref.getGrade() << ">" << std::endl;
	return out;
}