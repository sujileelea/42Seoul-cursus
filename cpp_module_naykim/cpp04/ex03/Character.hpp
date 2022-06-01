#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "ICharacter.hpp"

class Character: public ICharacter {
private:
	std::string _name;
	AMateria* _inventory[INVEN_SIZE];
public:
	AMateria* getAMateria(int idx) const;
	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
	
	Character();
	Character(const std::string& name);
	Character(const Character& copy);
	Character& operator=(const Character& origin);
	~Character();
};

#endif