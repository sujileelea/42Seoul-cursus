#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name) {
	weapon = 0;
}

HumanB::HumanB(std::string name, Weapon weapon) : name(name) {
	this->weapon = &weapon;
}

void HumanB::setWeapon(Weapon &weapon) {
	this->weapon = &weapon;
}

void HumanB::attack() {
	if (weapon == 0 || weapon->getType().length() == 0)
		std::cout << name << " has no weapon" << std::endl;
	else
		std::cout << name << " attacks with his " << weapon->getType() << std::endl;
}

HumanB::~HumanB() {}