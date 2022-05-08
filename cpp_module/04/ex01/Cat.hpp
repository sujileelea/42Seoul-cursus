#ifndef __CAT_HPP__
#define __CAT_HPP__

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain*	_brain;
	public:
		Cat();
		Cat(const Cat& original);
		~Cat();

		Cat&				operator=(const Cat& original);
		void				makeSound() const;
		void				addIdea(std::string idea);
		const std::string&	getIdea(unsigned int idx) const;
};


#endif
