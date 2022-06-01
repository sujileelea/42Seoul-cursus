#ifndef __SCAVTRAP_H__
#define __SCAVTRAP_H__

#include "ClapTrap.hpp"

#define S_HITPOINT 100
#define S_ENERGYPOINT 50
#define S_ATTACKDAMAGE 20

class ScavTrap: virtual public ClapTrap {
protected:
	bool _guardMode;
public:
	void attack(const std::string &target);
	void beRepaired(unsigned int amount);
	bool getGuardMode() const;
	void guardGate() const;
	void printStatus() const;

	ScavTrap();
	ScavTrap(const std::string name);
	ScavTrap(const ScavTrap &origin);
	ScavTrap &operator=(const ScavTrap &origin);
	~ScavTrap();
};

#endif