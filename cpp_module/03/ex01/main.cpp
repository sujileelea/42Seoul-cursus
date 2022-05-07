#include "ScavTrap.hpp"

int main() {
	ScavTrap	sujilee("sujilee");
	ScavTrap	kchoi("kchoi");

	std::cout << std::endl;
	sujilee.printStatus();
	std::cout << "-------------" << std::endl;
	kchoi.printStatus();

	std::cout << std::endl;
	std::cout << std::endl;

	sujilee.attack(kchoi.getName());
	kchoi.takeDamage(sujilee.getAttackDamage());
	std::cout << std::endl;
	kchoi.printStatus();

	kchoi.beRepaired(10);
	std::cout << std::endl;
	kchoi.printStatus();

	sujilee.guardGate();
	kchoi.guardGate();

	return 0;
}