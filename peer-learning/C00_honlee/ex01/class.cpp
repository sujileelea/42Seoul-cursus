/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 20:44:45 by honlee            #+#    #+#             */
/*   Updated: 2021/04/08 13:21:38 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "class.hpp"

std::string		to_str(int idx)
{
	std::stringstream toStr;
	toStr << idx;
	
	return (toStr.str());
}

std::string		to_ten(std::string str)
{
	std::string ret;

	if (str.length() > 10)
	{
		ret = str.substr(0, 9);
		ret += '.';
		return (ret);
	}
	return (str);
}

Contact::Contact()
{
	this->is_empty = true;
	this->index = -1;
}

Contact::Contact(int idx)
{
	this->is_empty = true;
	this->index = idx;
}

void	Contact::print()
{
	if (this->is_empty == false && this->index > -1)
	{
		std::cout.setf(std::ios::right);
		std::cout << '|';
		std::cout << std::setw(10) << to_ten(to_str(this->index));
		std::cout << '|';
		std::cout << std::setw(10) << to_ten(this->first_name);
		std::cout << '|';
		std::cout << std::setw(10) << to_ten(this->last_name);	
		std::cout << '|';
		std::cout << std::setw(10) << to_ten(this->nick_name);	
		std::cout << '|' << std::endl;
	}
	else
		std::cout << "is_empty : " << this->is_empty << "  |   idx : " << this->index << std::endl;
}

void	Contact::printAll()
{
	std::cout.setf(std::ios::right);
	std::cout << std::setw(20) << "index > " << this->index << std::endl;
	std::cout << std::setw(20) << "first name > " << this->first_name << std::endl;
	std::cout << std::setw(20) << "last name > " << this->last_name << std::endl;
	std::cout << std::setw(20) << "nick name > " << this->nick_name << std::endl;
	std::cout << std::setw(20) << "login > " << this->login << std::endl;
	std::cout << std::setw(20) << "postal address > " << this->postal_address << std::endl;
	std::cout << std::setw(20) << "email address > " << this->email_address << std::endl;
	std::cout << std::setw(20) << "phone number > " << this->phone_number << std::endl;
	std::cout << std::setw(20) << "birthday date > " << this->birthday_date << std::endl;
	std::cout << std::setw(20) << "favorite meal > " << this->favorite_meal << std::endl;
	std::cout << std::setw(20) << "underwear color > " << this->underwear_color << std::endl;
	std::cout << std::setw(20) << "darkest secret > " << this->darkest_secret << std::endl;
}

void Contact::setIndex(int idx)
{
	this->index = idx;
	this->is_empty = false;
}

void Contact::setFirstName(std::string first_name)
{
	this->first_name = first_name;
}

void Contact::setLastName(std::string last_name)
{
	this->last_name = last_name;
}

void Contact::setNickName(std::string nick_name)
{
	this->nick_name = nick_name;
}

void Contact::setLogin(std::string login)
{
	this->login = login;
}

void Contact::setPostalAddress(std::string postal_address)
{
	this->postal_address = postal_address;
}

void Contact::setEmailAddress(std::string email_address)
{
	this->email_address = email_address;
}

void Contact::setPhoneNumber(std::string phone_number)
{
	this->phone_number = phone_number;
}

void Contact::setBirthdayDate(std::string birthday_date)
{
	this->birthday_date = birthday_date;
}

void Contact::setFavoriteMeal(std::string favorite_meal)
{
	this->favorite_meal = favorite_meal;
}

void Contact::setUnderwearColor(std::string underwear_color)
{
	this->underwear_color = underwear_color;
}

void Contact::setDarkestSecret(std::string darkest_secret)
{
	this->darkest_secret = darkest_secret;
}

int			Contact::getIndex(void)
{
	return (this->index);
}

std::string Contact::getFirstName(void)
{
	return (this->first_name);
}

std::string Contact::getLastName(void)
{
	return (this->last_name);
}

std::string Contact::getNickName(void)
{
	return (this->nick_name);
}

std::string Contact::getLogin(void)
{
	return (this->login);
}

std::string Contact::getPostalAddress(void)
{
	return (this->postal_address);
}

std::string Contact::getEmailAddress(void)
{
	return (this->email_address);
}

std::string Contact::getPhoneNumber(void)
{
	return (this->phone_number);
}

std::string Contact::getBirthdayDate(void)
{
	return (this->birthday_date);
}

std::string Contact::getFavoriteMeal(void)
{
	return (this->favorite_meal);
}

std::string Contact::getUnderwearColor(void)
{
	return (this->underwear_color);
}

std::string Contact::getDarkestSecret(void)
{
	return (this->darkest_secret);
}