#ifndef __DOG_H__
#define __DOG_H__

#include "Animal.hpp"

class Dog: public Animal {
public:
	void setType(const std::string type);
	void makeSound() const;

	Dog();
	Dog(std::string type);
	Dog(const Dog &origin);
	Dog& operator=(const Dog &origin);
	~Dog();
};

#endif