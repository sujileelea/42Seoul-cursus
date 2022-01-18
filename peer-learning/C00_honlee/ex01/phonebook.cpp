/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 20:30:56 by honlee            #+#    #+#             */
/*   Updated: 2021/04/08 13:28:08 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "class.hpp"

int		get_next_line(std::string &input)
{
	std::getline(std::cin, input);
	if (std::cin.eof())
	{
		std::cout << "Do not input EOF" << std::endl;
		return (1);
	}
	return (0);
}

int		make_contact(int idx, Contact &ret)
{
	std::string input;

	ret.setIndex(idx);
	std::cout << "first name > ";
	if (get_next_line(input) != 0)
		return (1);
	ret.setFirstName(input);

	std::cout << "last name > ";
	if (get_next_line(input) != 0)
		return (1);
	ret.setLastName(input);

	std::cout << "nick name > ";
	if (get_next_line(input) != 0)
		return (1);
	ret.setNickName(input);

	std::cout << "login > ";
	if (get_next_line(input) != 0)
		return (1);
	ret.setLogin(input);

	std::cout << "postal address > ";
	if (get_next_line(input) != 0)
		return (1);
	ret.setPostalAddress(input);

	std::cout << "email address > ";
	if (get_next_line(input) != 0)
		return (1);
	ret.setEmailAddress(input);

	std::cout << "phone number > ";
	if (get_next_line(input) != 0)
		return (1);
	ret.setPhoneNumber(input);

	std::cout << "birthday date > ";
	if (get_next_line(input) != 0)
		return (1);
	ret.setBirthdayDate(input);

	std::cout << "favorite meal > ";
	if (get_next_line(input) != 0)
		return (1);
	ret.setFavoriteMeal(input);

	std::cout << "underwear color > ";
	if (get_next_line(input) != 0)
		return (1);
	ret.setUnderwearColor(input);

	std::cout << "darkest secret > ";
	if (get_next_line(input) != 0)
		return (1);
	ret.setDarkestSecret(input);

	return (0);
}

int		convert_to_int(std::string str)
{
	int					ret;
	std::stringstream	toInt(str);

	ret = -1;
	toInt >> ret;
	if (!toInt.fail())
		return (ret);
	return (-1);
}

int		main()
{
	std::string			order;
	Contact				book[8];
	int					idx;

	idx = -1;
	while (1)
	{
		std::cout << "ORDER > ";
		if (get_next_line(order) != 0)
			return (0);
		if (order.compare("ADD") == 0)
		{
			//ADD
			if (idx + 1 > 7)
				std::cout << "Can not ADD more than 8" << std::endl;
			else
			{
				idx++;
				if (make_contact(idx, book[idx]) != 0)
					return (0);
			}
		}
		else if (order.compare("SEARCH") == 0)
		{
			int idx_in;
			std::string input;

			if (idx != -1)
			{
				std::cout << "--------idx-first name--last name--nick name-" << std::endl;;
				for (int i = 0; i <= idx; i++)
				{
					book[i].print();
				}
				std::cout << "---------------------------------------------" << std::endl;
			}
			std::cout << "SEARCH INDEX > ";
			if (get_next_line(input) != 0)
				return (0);
			idx_in = convert_to_int(input);
			if (idx != -1 && idx_in <= idx && idx_in >= 0)
				book[idx_in].printAll();		
			else
				std::cout << "please check your input" << std::endl;
		}
		else if (order.compare("EXIT") == 0)
			return (0);
		else
			std::cout << "please check your input" << std::endl;
	}
}
