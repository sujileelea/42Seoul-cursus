#ifndef __DOG_HPP__
#define __DOG_HPP__

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain*	_brain;
	public:
		Dog();
		Dog(const Dog& original);
		~Dog();

		Dog&				operator=(const Dog& original);
		void				makeSound() const;
		void				addIdea(std::string idea);
		const std::string&	getIdea(unsigned int idx) const;
};

#endif
