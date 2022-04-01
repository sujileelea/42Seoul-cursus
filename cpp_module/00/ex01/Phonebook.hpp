/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:28:51 by sujilee           #+#    #+#             */
/*   Updated: 2022/04/01 10:52:23 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"

class PhoneBook {
	private: 
			Contact contact[8];
			int		currIdx;
	public:
			PhoneBook();
			void		ShowPhoneBook();
			void		AddContact();
			void		SearchIndex();
			std::string ShortenString(std::string str);
			~PhoneBook();
};

#endif
