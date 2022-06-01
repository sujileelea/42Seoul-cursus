#include "Karen.hpp"

int main(int ac, char **av) {
	Karen karen;

	if (ac != 2)
	{
		std::cout << "You need one string argument." << std::endl;
		return 1;
	}
	karen.complain(av[1]);

	return 0;
}