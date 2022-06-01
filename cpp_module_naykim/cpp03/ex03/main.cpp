#include "DiamondTrap.hpp"

int main() {
	DiamondTrap diamond("diamond");

	diamond.whoAmI();
	std::cout << std::endl;

	diamond.printStatus();
	std::cout << std::endl;
	
	diamond.attack("other");
	diamond.printStatus();
	std::cout << std::endl;
	
	// diamond.beRepaired(45);
	// diamond.takeDamage(20);
	
	return 0;
}