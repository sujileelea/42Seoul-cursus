#ifndef __WRONGANIMAL_HPP__
#define __WRONGANIMAL_HPP__

#include <iostream>

class WrongAnimal
{
	protected:
		std::string _type;
	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal& ref);
		virtual ~WrongAnimal(void);

		WrongAnimal&	operator=(const WrongAnimal& ref);
		std::string		getType(void) const;
		void			setType(std::string type);
		void			makeSound(void) const;
};

#endif
