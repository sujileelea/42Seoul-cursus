#ifndef __CLAPTRAP_H__
#define __CLAPTRAP_H__

#include <string>
#include <iostream>
#include <iomanip>

#define C_HITPOINT 10
#define C_ENERGYPOINT 10
#define C_ATTACKDAMAGE 0

class ClapTrap {
protected:
	std::string _name;
	unsigned int _hitPoint;
	unsigned int _energyPoint;
	unsigned int _attackDamage;

public:
	void attack(std::string const &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void printStatus() const;

	std::string getName() const;
	unsigned int getHit() const;
	unsigned int getEp() const;
	unsigned int getAd() const;

	void setName(const std::string &name);
	void setHit(unsigned int hit);
	void setEp(unsigned int energyPoint);
	void setAd(unsigned int attackDamage);

	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& origin);
	ClapTrap& operator=(const ClapTrap& origin);
	~ClapTrap();
};

#endif