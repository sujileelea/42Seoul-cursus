/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:26:19 by sujilee           #+#    #+#             */
/*   Updated: 2022/05/11 11:15:32 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int	main(void)
{
	Bureaucrat	eelijus("sujilee", 1);
	Intern		someRandomIntern;

	Form* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	eelijus.signForm(*rrf);
	eelijus.executeForm(*rrf);
	Form* scf = someRandomIntern.makeForm("shrubbery creation", "Bender");
	eelijus.signForm(*scf);
	eelijus.executeForm(*scf);
	Form* ppf = someRandomIntern.makeForm("presidential pardon", "Bender");
	eelijus.signForm(*ppf);
	eelijus.executeForm(*ppf);

	delete rrf;
	delete scf;
	delete ppf;
	return 0;
}