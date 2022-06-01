#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <ctime>

int	main(void)
{
	Form	*form = NULL;
	Bureaucrat	bob("bob", 1);
	Bureaucrat	phil("phil", 40);
	Bureaucrat	luc("luc", 150);

	std::cout << "=======================================" << std::endl;
	std::cout << "     PresidentialPardonForm Test" << std::endl;
	try
	{
		form = new PresidentialPardonForm("28A");
		std::cout << "--bob shouldn't success. There's no sign.--" << std::endl;
		form->execute(bob);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	if (form) {
		delete form;
		form = NULL;
	}

	try
	{
		form = new PresidentialPardonForm("28A");
		std::cout << "--bob should success.--" << std::endl;
		bob.signForm(*form);
		form->execute(bob);
		std::cout << "--phil and luc shouldn't success.--" << std::endl;
		phil.signForm(*form);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	if (form) {
		delete form;
		form = NULL;
	}
	std::cout << "=======================================" << std::endl;

	std::cout << std::endl;
	std::cout << "=======================================" << std::endl;
	std::cout << "     RobotomyRequestForm Test" << std::endl;
	try
	{
		srand((unsigned int)time(NULL));
		form = new RobotomyRequestForm("28B");
		bob.signForm(*form);
		form->execute(phil);
		form->execute(phil);
		form->execute(phil);
		form->execute(phil);
		form->execute(phil);
		form->execute(phil);
		form->execute(phil);
		form->execute(phil);
		form->execute(phil);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	if (form) {
		delete form;
		form = NULL;
	}
	std::cout << "=======================================" << std::endl;


	std::cout << std::endl;
	std::cout << "=======================================" << std::endl;
	std::cout << "    ShrubberyCreationForm Test" << std::endl;
	try
	{
		form = new ShrubberyCreationForm("28C");
		bob.signForm(*form);
		form->execute(phil);
		form->execute(luc);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	if (form) {
		delete form;
		form = NULL;
	}
	std::cout << "=======================================" << std::endl;

	return 0;
}