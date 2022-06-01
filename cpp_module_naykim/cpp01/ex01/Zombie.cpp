#include "Zombie.hpp"

Zombie::Zombie() : name("default") {}

Zombie::Zombie(std::string name) : name(name) {}

void Zombie::announce() {
	std::cout << name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) {
	this->name = name;
}

Zombie::~Zombie() {
	std::cout << name << " is destroyed" << std::endl;
}
