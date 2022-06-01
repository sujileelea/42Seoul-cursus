#include "Zombie.hpp"

int main()
{
	Zombie* zombies = Zombie::zombieHorde(5, "naykim");

	for (int i = 0; i < 5; i++)
		zombies[i].announce();
	delete[] zombies;
	return 0;
}