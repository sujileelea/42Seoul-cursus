#include "Weapon.hpp"

Weapon::Weapon() {}

Weapon::Weapon(std::string type) : type(type) {}

const std::string& Weapon::getType() const {
	const std::string& typeREF = type;

	return typeREF;
}

void Weapon::setType(std::string type) {
	this->type = type;
}

Weapon::~Weapon() {}