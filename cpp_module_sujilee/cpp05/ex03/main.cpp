#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include <ctime>

int	main(void)
{
	Intern intern;
	Bureaucrat naykim("naykim", 5);
	Form *form;

	std::cout << "\n===========this one doesn't exist" << std::endl;
	try {
		form = intern.makeForm("this one doesn't exist", "Justin");
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	if (form)
		delete form;

	std::cout << "\n===========president" << std::endl;
	try {
		form = intern.makeForm("president", "Maynard");
		form->beSigned(naykim);
		form->execute(naykim);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	if (form)
		delete form;

	std::cout << "\n===========shrubbery" << std::endl;
	try {
		form = intern.makeForm("shrubbery", "Danny");
		form->beSigned(naykim);
		form->execute(naykim);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	if (form)
		delete form;

	std::cout << "\n===========robotomy" << std::endl;
	try {
		srand((unsigned int)time(NULL));
		form = intern.makeForm("robotomy", "Adam");
		form->beSigned(naykim);
		form->execute(naykim);
		form->execute(naykim);
		form->execute(naykim);
		form->execute(naykim);
		form->execute(naykim);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	if (form)
		delete form;

	return 0;
}