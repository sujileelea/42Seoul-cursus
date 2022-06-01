#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"

class PhoneBook {
	private:
			int	currIdx;
			Contact contact[8];
	public:
			PhoneBook();
			void	addContact();
			void	showContact();
			void	searchContact();
			void	exitContact();
			void	shortedString(std::string str);
			~PhoneBook();
};

#endif;
