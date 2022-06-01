/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:13:52 by sujilee           #+#    #+#             */
/*   Updated: 2022/06/01 16:16:07 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <ctime>

int	main(void)
{
	Form	*form = NULL;
	Bureaucrat	sujilee("sujilee", 1);
	Bureaucrat	DDUDDU("DDUDDU", 40);
	Bureaucrat	kchoi("kchoi", 150);

	std::cout << "=======================================" << std::endl;
	std::cout << "     PresidentialPardonForm Test" << std::endl;
	try
	{
		form = new PresidentialPardonForm("President");
		std::cout << "--sujilee shouldn't success. There's no sign.--" << std::endl;
		form->execute(sujilee);
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
		form = new PresidentialPardonForm("President");
		std::cout << "--sujilee should success.--" << std::endl;
		sujilee.signForm(*form);
		form->execute(sujilee);
		std::cout << "--DDUDDU and kchoi shouldn't success.--" << std::endl;
		DDUDDU.signForm(*form);
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
		form = new RobotomyRequestForm("Robot");
		sujilee.signForm(*form);
		form->execute(DDUDDU);
		form->execute(DDUDDU);
		form->execute(DDUDDU);
		form->execute(DDUDDU);
		form->execute(DDUDDU);
		form->execute(DDUDDU);
		form->execute(DDUDDU);
		form->execute(DDUDDU);
		form->execute(DDUDDU);
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
		form = new ShrubberyCreationForm("Berry");
		sujilee.signForm(*form);
		form->execute(DDUDDU);
		form->execute(kchoi);
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