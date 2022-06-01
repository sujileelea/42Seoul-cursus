#ifndef __DIAMONDTRAP_H__
#define __DIAMONDTRAP_H__

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public ScavTrap , public FragTrap {
private:
	std::string _name;
public:
	void whoAmI() const;
	void printStatus() const;
	void attack(const std::string& target);

	DiamondTrap();
	DiamondTrap(const std::string name);
	DiamondTrap(const DiamondTrap &origin);
	DiamondTrap& operator=(const DiamondTrap &origin);
	~DiamondTrap();
};

#endif