/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:35:20 by sujilee           #+#    #+#             */
/*   Updated: 2022/03/28 15:34:54 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int		main(int argc, char **argv)
{
	std::string	speech;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}	

	for (int i = 1; i < argc; i++)
		speech = speech + argv[i];

	for (int i = 0; i < speech.length(); i++)
		speech[i] = toupper(speech[i]);

	std::cout << speech << std::endl;

}