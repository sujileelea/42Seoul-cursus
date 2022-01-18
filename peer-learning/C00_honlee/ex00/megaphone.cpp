/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 00:50:19 by honlee            #+#    #+#             */
/*   Updated: 2021/04/07 01:13:11 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <algorithm>

int		main(int ac, char **av)
{
	int			idx;

	if (ac <= 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	else
	{
		idx = 0;
		while (++idx < ac)
		{
			std::string temp(av[idx]);
			std::transform(temp.begin(), temp.end(), temp.begin(), toupper);
			std::cout << temp;
		}
		std::cout << std::endl;
	}
}