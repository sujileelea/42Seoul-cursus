#ifndef __FRAGTRAP_H__
#define __FRAGTRAP_H__

#include "ClapTrap.hpp"

#define F_HITPOINT 100
#define F_ENERGYPOINT 100
#define F_ATTACKDAMAGE 30

class FragTrap: public ClapTrap {
public:
	void highFivesGuys() const;
	void printStatus() const;
	void attack(const std::string &target);
	void beRepaired(unsigned int amount);

	FragTrap();
	FragTrap(const std::string name);
	FragTrap(const FragTrap &origin);
	FragTrap &operator=(const FragTrap &origin);
	~FragTrap();
};

#endif