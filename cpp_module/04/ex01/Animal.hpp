#ifndef __ANIMAL_HPP__
#define __ANIMAL_HPP__

#include <iostream>

class Animal
{
	protected:
		std::string	_type;
	public:
		Animal(void);
		Animal(const Animal& ref);
		virtual ~Animal(void);

		Animal&			operator=(const Animal& ref);
		std::string		getType(void) const;
		void			setType(std::string type);
		virtual void	makeSound(void) const;
};

#endif
