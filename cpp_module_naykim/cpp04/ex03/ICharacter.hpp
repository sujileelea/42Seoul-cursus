#ifndef __ICHARACTER_H__
#define __ICHARACTER_H__

#include "AMateria.hpp"
#include <string>

#define INVEN_SIZE 4

class AMateria;

class ICharacter {
public:
	virtual std::string const & getName() const = 0;
	virtual void equip(AMateria* m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter& target) = 0;

	virtual ~ICharacter() {}
};

#endif