#include "Character.hpp"

AMateria* Character::getAMateria(int idx) const {
	if (idx >= 0 && idx < INVEN_SIZE && _inventory[idx])
		return _inventory[idx];
	return NULL;
}

std::string const &Character::getName() const {
	return _name;
}

void Character::equip(AMateria* m) {
	for (int i = 0; i < INVEN_SIZE; i++) {
		if (_inventory[i] == 0) {
			_inventory[i] = m;
			return;
		}
	}
	std::cout << "no space in inventory. FAIL to equip" << std::endl;
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx < INVEN_SIZE && _inventory[idx]) {
		_inventory[idx] = 0;
		return;
	}
	std::cout << "wrong index. FAIL to unequip" << std::endl;
}

void Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx < INVEN_SIZE && _inventory[idx]) {
		_inventory[idx]->use(target);
		return;
	}
	std::cout << "wrong index. FAIL to use" << std::endl;
}

Character::Character(): _name("") {
	std::cout << "Character Default constructor called" << std::endl;
	for (int i = 0; i < INVEN_SIZE; ++i)
		_inventory[i] = 0;
}

Character::Character(const std::string& name): _name(name) {
	std::cout << "Character constructor with name \"" << name << "\" called" << std::endl;
	for (int i = 0; i < INVEN_SIZE; ++i)
		_inventory[i] = 0;
}

Character::Character(const Character& copy) {
	std::cout << "Character copy constructor called" << std::endl;
	*this = copy;
}

Character& Character::operator=(const Character& origin) {
	std::cout << "Character assignation operator called" << std::endl;
	for (int i = 0; i < INVEN_SIZE; i++) {
		_inventory[i] = origin.getAMateria(i);
	}
	return *this;
}

Character::~Character() {
	for (int i = 0; i < INVEN_SIZE; i++) {
		if (_inventory[i])
			delete _inventory[i];
		_inventory[i] = 0;
	}
	std::cout << "Character " << _name << " destructor called" << std::endl;
}