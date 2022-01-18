/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 20:39:29 by honlee            #+#    #+#             */
/*   Updated: 2021/04/08 13:21:31 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_HPP
# define CLASS_HPP

# include <iostream>
# include <string>
# include <algorithm>
# include <iomanip>
# include <sstream>

class Contact{
	private :
		bool		is_empty;
		int			index;
		std::string first_name;
		std::string last_name;
		std::string nick_name;
		std::string login;
		std::string postal_address;
		std::string email_address;
		std::string phone_number;
		std::string birthday_date;
		std::string favorite_meal;
		std::string underwear_color;
		std::string darkest_secret;
	public :
		Contact(void);
		Contact(int idx);
		void print(void);
		void printAll(void);

		void setIndex(int idx);
		void setFirstName(std::string first_name);
		void setLastName(std::string last_name);
		void setNickName(std::string nick_name);
		void setLogin(std::string login);
		void setPostalAddress(std::string postal_address);
		void setEmailAddress(std::string email_address);
		void setPhoneNumber(std::string phone_number);
		void setBirthdayDate(std::string birthday_date);
		void setFavoriteMeal(std::string favorite_meal);
		void setUnderwearColor(std::string underwear_color);
		void setDarkestSecret(std::string darkest_secret);

		int			getIndex(void);
		std::string getFirstName(void);
		std::string getLastName(void);
		std::string getNickName(void);
		std::string getLogin(void);
		std::string getPostalAddress(void);
		std::string getEmailAddress(void);
		std::string getPhoneNumber(void);
		std::string getBirthdayDate(void);
		std::string getFavoriteMeal(void);
		std::string getUnderwearColor(void);
		std::string getDarkestSecret(void);
};

#endif