#include "whatever.hpp"
#include <iostream>
#include <string>

int main() {
	int ia = 10;
	int ib = 7;
	double da = 10.5;
	double db = 7.8;
	std::string s1 = "hello";
	std::string s2 = "world";

	std::cout << "ia: " << ia << std::endl;
	std::cout << "ib: " << ib << std::endl;
	swap(ia, ib);
	std::cout << "after swap" << std::endl;
	std::cout << "ia: " << ia << std::endl;
	std::cout << "ib: " << ib << std::endl << std::endl;
	std::cout << "min(ia, ib): " << min(ia, ib) << std::endl;
	std::cout << "max(ia, ib): " << max(ia, ib) << std::endl << std::endl;

	std::cout << "da: " << da << std::endl;
	std::cout << "db: " << db << std::endl;
	swap(da, db);
	std::cout << "after swap" << std::endl;
	std::cout << "da: " << da << std::endl;
	std::cout << "db: " << db << std::endl << std::endl;
	std::cout << "min(da, db): " << min(da, db) << std::endl;
	std::cout << "max(da, db): " << max(da, db) << std::endl << std::endl;

	std::cout << "s1: " << s1 << std::endl;
	std::cout << "s2: " << s2 << std::endl;
	swap(s1, s2);
	std::cout << "after swap" << std::endl;
	std::cout << "s1: " << s1 << std::endl;
	std::cout << "s2: " << s2 << std::endl << std::endl;

	return 0;
}