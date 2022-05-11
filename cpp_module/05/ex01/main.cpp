/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:26:19 by sujilee           #+#    #+#             */
/*   Updated: 2022/05/11 09:30:17 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int	main(void) {
    try {
        Bureaucrat sujilee("sujilee", 50);
        Form form("form", 49, 30);

        std::cout << sujilee;
        std::cout << form;
        sujilee.signForm(form);
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}