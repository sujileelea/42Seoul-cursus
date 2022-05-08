#ifndef __WRONGANIMAL_HPP__
#define __WRONGANIMAL_HPP__

#include <iostream>

class WrongAnimal
{
	protected:
		std::string _type;
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& original);
		virtual ~WrongAnimal();

		WrongAnimal&	operator=(const WrongAnimal& original);
		std::string		getType() const;
		void			setType(std::string type);
		void			makeSound() const;
};

#endif
