#ifndef __DOG_HPP__
#define __DOG_HPP__

#include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog(void);
		Dog(const Dog& ref);
		~Dog(void);

		Dog&	operator=(const Dog& ref);
		void	makeSound(void) const;
};

#endif
