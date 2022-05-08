#ifndef __ANIMAL_HPP__
#define __ANIMAL_HPP__

#include <iostream>

class Animal
{
	protected:
		std::string	_type;
	public:
		Animal();
		Animal(const Animal& original);
		virtual ~Animal();

		Animal&			operator=(const Animal& original);
		std::string		getType() const;
		void			setType(std::string type);
		virtual void	makeSound() const;
};

#endif
