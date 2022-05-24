/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 11:55:48 by sujilee           #+#    #+#             */
/*   Updated: 2022/05/14 11:56:22 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConversion.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
		std::cout << "Invalid arguments!" << std::endl;
	else
	{
		ScalarConversion	sc(argv[1]);

		sc.convertChar();
		sc.convertInt();
		sc.convertFloat();
		sc.convertDouble();
	}
	return 0;
}