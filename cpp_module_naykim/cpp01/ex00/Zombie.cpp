#include "Zombie.hpp"

Zombie::Zombie() : name("default") {}

Zombie::Zombie(std::string name) : name(name) {}

void Zombie::announce() {
	std::cout << name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie() {
	std::cout << name << " is destroyed" << std::endl;
}