/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:26:19 by sujilee           #+#    #+#             */
/*   Updated: 2022/05/11 10:34:42 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void) {
    Bureaucrat eelijus("sujilee", 5);
    std::cout << eelijus;

    ShrubberyCreationForm s("rose");
    eelijus.signForm(s);
    eelijus.executeForm(s);

    RobotomyRequestForm r("drill");
    eelijus.signForm(r);
    eelijus.executeForm(r);

    PresidentialPardonForm p("pardon");
    eelijus.signForm(p);
    eelijus.executeForm(p);

    eelijus.downGrade(140);
    eelijus.signForm(s);
    eelijus.executeForm(s);
    eelijus.signForm(r);
    eelijus.executeForm(r);
    eelijus.signForm(p);
    eelijus.executeForm(p);

    return 0;
}