#include "Karen.hpp"

int main() {
	Karen karen;
	
	karen.complain("DEBUG");
	karen.complain("INFO");
	karen.complain("WARNING");
	karen.complain("ERROR");
	karen.complain("warning");
	karen.complain("InfO");
	karen.complain("DEBUg");
	karen.complain("NOTHING");

	return 0;
}