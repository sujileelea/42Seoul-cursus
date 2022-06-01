#include "Form.hpp"

std::string Form::getName() const {
	return _name;
}

bool Form::getIsSigned() const {
	return _isSigned;
}

int Form::getGradeForSign() const {
	return _gradeForSign;
}

int Form::getGradeForExec() const {
	return _gradeForExec;
}

void Form::beSigned(const Bureaucrat& crat) {
	if (crat.getGrade() > this->_gradeForSign)
		throw Form::GradeTooLowException();
	this->_isSigned = true;
}

void Form::isExecutable(const Bureaucrat& executor) const {
	if (this->_isSigned == false || executor.getGrade() > this->_gradeForExec)
		throw Form::CantExecute();
}

const char* Form::GradeTooHighException::what(void) const throw() {
	return "Grade is too high.";
}

const char* Form::GradeTooLowException::what(void) const throw() {
	return "Grade is too low.";
}

const char* Form::CantExecute::what(void) const throw() {
	return "Form isn't executable. Form isn't signed or Form's grade for execute is too HIGH.";
}

Form::Form(): _name(""), _isSigned(false), _gradeForSign(Form::lowestGrade), _gradeForExec(Form::lowestGrade) {
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string name, const int forSign, const int forExec):
	_name(name), _isSigned(false), _gradeForSign(forSign), _gradeForExec(forExec) {
	std::cout << "Form constructor with arguments called" << std::endl;
	if (_gradeForSign < Form::highestGrade || _gradeForExec < Form::highestGrade)
		throw Form::GradeTooHighException();
	if (_gradeForSign > Form::lowestGrade || _gradeForExec > Form::lowestGrade)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& copy) {
	std::cout << "Form copy constructor called" << std::endl;
	*this = copy;
}

Form& Form::operator=(const Form& origin) {
	std::cout << "Form assignation operator called" << std::endl;
	if (this != &origin) {
		this->_name = origin.getName();
		this->_isSigned = origin.getIsSigned();
		this->_gradeForSign = origin.getGradeForSign();
		this->_gradeForExec = origin.getGradeForExec();
	}
	return (*this);
}

Form::~Form() {
	std::cout << "Form " << _name << " destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Form &ref) {
	out << std::endl;
	out << std::setw(30) << std::setfill('-') << ref.getName() + "'s status--------" << std::setfill(' ') << std::endl;
	out << std::setw(20) << "name: " << ref.getName() << std::endl;
	out << std::setw(20) << "isSigned: " << (ref.getIsSigned() == true ? "true" : "false") << std::endl;
	out << std::setw(20) << "grade for sign: " << ref.getGradeForSign() << std::endl;
	out << std::setw(20) << "grade for execute: " << ref.getGradeForExec() << std::endl;
	out << std::setw(30) << std::setfill('-') << "\n" << std::endl;
	out << std::setfill(' ');
	return out;
}