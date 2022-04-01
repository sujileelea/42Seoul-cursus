/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:39:46 by sujilee           #+#    #+#             */
/*   Updated: 2022/04/01 10:52:48 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

#include <iostream>
#include <cstring>
#include <iomanip>

class Contact {
	private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkestSecret;

	public:
		Contact();
		std::string GetFirstName() const;
		std::string GetLastName() const;
		std::string GetNickName()const;
		std::string GetPhoneNumber() const;
		std::string GetDarkestSecret() const;
		void		SetFirstName(std::string str);
		void		SetLastName(std::string str);
		void		SetNickName(std::string str);
		void		SetPhoneNumber(std::string str);
		void		SetDarkestSecret(std::string str);
		void		ShowInfo();
		~Contact();
};

#endif