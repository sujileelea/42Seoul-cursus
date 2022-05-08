#ifndef __CAT_HPP__
#define __CAT_HPP__

#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat(void);
		Cat(const Cat& ref);
		~Cat(void);

		Cat&	operator=(const Cat& ref);
		void	makeSound(void) const;
};


#endif
