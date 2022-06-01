#include "ClapTrap.hpp"

int main() {
	ClapTrap clap1("clap1");
	ClapTrap clap2(clap1);

	clap2.setName("clap2");
	clap1.printStatus();
	clap2.printStatus();

	clap1.attack("someone");
	clap1.takeDamage(10);
	clap1.printStatus();

	clap2.takeDamage(3);
	clap2.printStatus();

	clap1.beRepaired(10);
	clap1.printStatus();

	clap2.beRepaired(45);
	clap2.printStatus();

	return 0;
}