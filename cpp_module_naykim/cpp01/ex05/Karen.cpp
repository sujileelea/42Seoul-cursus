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
	void (Karen::*f[4])() = {&Karen::debug, &Karen::info, &Karen::warning, &Karen::error};

	for (int i = 0; i < 4; i++) {
		if (command[i] == level)
			return (this->*(f[i]))();
	}
	std::cout << "This is nothing. Ignore this message." << std::endl;
}