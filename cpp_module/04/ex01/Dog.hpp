#ifndef __DOG_HPP__
#define __DOG_HPP__

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain*	_brain;
	public:
		Dog(void);
		Dog(const Dog& ref);
		~Dog(void);

		Dog&				operator=(const Dog& ref);
		void				makeSound(void) const;
		void				addIdea(std::string idea);
		const std::string&	getIdea(unsigned int idx) const;
};

#endif
