#include "FragTrap.hpp"

int main() {
	FragTrap	sujilee("sujilee");
	FragTrap	kchoi("kchoi");

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

	sujilee.highFivesGuys();
	kchoi.highFivesGuys();

	return 0;
}