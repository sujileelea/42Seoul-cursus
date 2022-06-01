#include "Zombie.hpp"

Zombie* Zombie::zombieHorde(int N, std::string name)
{
	Zombie *zombies = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		std::string nowName = name + std::to_string(i + 1);
		zombies[i].setName(nowName);
	}
	return zombies;
}