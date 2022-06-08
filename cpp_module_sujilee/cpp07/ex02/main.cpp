#include <iostream>
#include "Array.hpp"

#define MAX_VAL 10

int main()
{
	std::cout << std::endl << "==================int test" << std::endl;

	int * a = new int();
	std::cout << *a << std::endl;


	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	std::cout << numbers << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		int value = rand() % 1000;
		numbers[i] = value;
		mirror[i] = value;
	}
	std::cout << numbers << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
		std::cout << "mirror[" << i << "]: " << mirror[i] << std::endl;
	std::cout << std::endl;


	std::cout << std::endl << "==================string test" << std::endl;
	Array<std::string> str(MAX_VAL);
	std::string* mirror2 = new std::string[MAX_VAL];
	srand(time(NULL));
	std::cout << str << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		std::string value = "";
		value.append(1, rand() % 10 + '0');
		str[i] = "number is " + value;
		mirror2[i] = "number is " + value;
	}
	std::cout << str << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
		std::cout << "mirror2[" << i << "]: " << mirror2[i] << std::endl;



	std::cout << std::endl << "==============exception test" << std::endl;
	try 
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try	
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try	
	{
		numbers[std::max(0, MAX_VAL - 1)] = 1000;
		std::cout << numbers << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	delete[] mirror;
	delete[] mirror2;

	return 0;
}
