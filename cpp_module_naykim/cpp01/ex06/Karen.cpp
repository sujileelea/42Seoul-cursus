#include "Karen.hpp"

Karen::Karen() {}

Karen::~Karen() {}

void Karen::debug() {
	std::cout << "[DEBUG] " << "This is debug message :(" << std::endl;
}

void Karen::info() {
	std::cout << "[INFO] " << "This is info message." << std::endl;
}

void Karen::warning() {
	std::cout << "[WARNING] " << "! This is warning message !" << std::endl;
}

void Karen::error() {
	std::cout << "[ERROR] " << "!!!! This is ERROR message !!!!" << std::endl;
}

void Karen::complain(std::string level) {
	std::string command[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int message = 5;
	
	for (int i = 0; i < 4; i++) {
		if (command[i] == level) {
			message = i;
			break;
		}
	}
	switch (message) {
	case 0:
		debug();
	case 1:
		info();
	case 2:
		warning();
	case 3:
		error();
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}