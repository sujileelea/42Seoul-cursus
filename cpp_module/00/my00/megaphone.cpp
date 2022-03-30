/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:08:54 by sujilee           #+#    #+#             */
/*   Updated: 2022/03/30 09:06:04 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

int		main(int argc, char **argv)
{
	if (argc == 1)
	{	std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}

	std::string speech;

	for (int i = 1; i < argc; i++)
		speech = speech + argv[i];
	
	for (int i = 0; i < speech.length(); i++)
		speech[i] = toupper(speech[i]);
	
	std::cout << speech << std::endl;
}