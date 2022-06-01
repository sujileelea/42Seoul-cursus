#ifndef __ROBOTOMYREQUESTFORM_H__
#define __ROBOTOMYREQUESTFORM_H__

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

class RobotomyRequestForm: public Form {
private:
	std::string _target;
public:
	const std::string& getTarget() const;
	void setTarget(std::string& target);
	void execute(const Bureaucrat& executor) const;

	RobotomyRequestForm();
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& copy);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& origin);
	~RobotomyRequestForm();
};

#endif