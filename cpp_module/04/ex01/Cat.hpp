#ifndef __CAT_HPP__
#define __CAT_HPP__

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain*	_brain;
	public:
		Cat(void);
		Cat(const Cat& ref);
		~Cat(void);

		Cat&				operator=(const Cat& ref);
		void				makeSound(void) const;
		void				addIdea(std::string idea);
		const std::string&	getIdea(unsigned int idx) const;
};


#endif
