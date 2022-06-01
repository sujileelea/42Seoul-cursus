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
			std::string getFirstName();
			std::string getLastName();
			std::string getNickName();
			std::string getPhoneNumber();
			std::string getDarkestSecret();

			void		setFirstName(std::string str);
			void		setLastName(std::string str);
			void		setNickName(std::string str);
			void		setPhoneNumber(std::string str);
			void		setDarkestSecret(std::string str);

			void		showInfo();

			~Contact();

};



#endif