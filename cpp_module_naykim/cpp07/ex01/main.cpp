#include <iostream>
#include "iter.hpp"

template<typename T>
void display(T &whatever) {
	std::cout << "value is: " << whatever << std::endl;
}

int	main( void ) {
	std::string	strTable[3];
	int			*intTable = new int[5];

	strTable[0] = "Hi how are you?";
	strTable[1] = "Fine, and you dear sir?";
	strTable[2] = "Very fine indeed!";
	iter(strTable, 3, &display);
	std::cout << std::endl;
	for (int i = 0; i < 5; i ++)
		intTable[i] = i * 3 + 7;
	iter(intTable, 5, &display);
	delete[] intTable;

	return 0;
}
