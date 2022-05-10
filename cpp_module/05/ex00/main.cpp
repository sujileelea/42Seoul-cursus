/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:26:19 by sujilee           #+#    #+#             */
/*   Updated: 2022/05/10 18:50:26 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main() {
    try
    {
        Bureaucrat sujilee("sujilee", 1);
        std::cout << sujilee;


        Bureaucrat kchoi("kchoi", 0);
        std::cout << kchoi;


        sujilee.upGrade(44);
        std::cout << sujilee;
        sujilee.downGrade(107);
        std::cout << sujilee;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}