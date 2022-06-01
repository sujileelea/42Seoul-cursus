/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:14:39 by sujilee           #+#    #+#             */
/*   Updated: 2022/06/01 17:07:20 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include <ctime>

int	main(void)
{
	Intern intern;
	Bureaucrat sujilee("sujilee", 5);
	Form *form;

	std::cout << "\n===========this one doesn't exist" << std::endl;
	try 
	{
		form = intern.makeForm("this one doesn't exist", "Justin");
	}
	catch (std::exception &e) 
	{
		std::cerr << e.what() << std::endl;
	}
	if (form)
		delete form;

	std::cout << "\n===========president" << std::endl;
	try 
	{
		form = intern.makeForm("president", "Maynard");
		form->beSigned(sujilee);
		form->execute(sujilee);
	}
	catch (std::exception &e) 
	{
		std::cerr << e.what() << std::endl;
	}
	if (form)
		delete form;

	std::cout << "\n===========shrubbery" << std::endl;
	try
	{
		form = intern.makeForm("shrubbery", "Danny");
		form->beSigned(sujilee);
		form->execute(sujilee);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	if (form)
		delete form;

	std::cout << "\n===========robotomy" << std::endl;
	try 
	{
		srand((unsigned int)time(NULL));
		form = intern.makeForm("robotomy", "Adam");
		form->beSigned(sujilee);
		form->execute(sujilee);
		form->execute(sujilee);
		form->execute(sujilee);
		form->execute(sujilee);
		form->execute(sujilee);
	}
	catch (std::exception &e) 
	{
		std::cerr << e.what() << std::endl;
	}
	if (form)
		delete form;

	return 0;
}