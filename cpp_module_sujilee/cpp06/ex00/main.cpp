#include "Conversion.hpp"

int main(int ac, char **av) {
	
	if (ac != 2) {
		std::cout << "PROGRAM WANTS ONLY ONE ARGUMENT" << std::endl;
		return (1);
	}
	Conversion cv(av[1]);

	cv.printAllType();
	return 0;
}