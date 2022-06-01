#include "FragTrap.hpp"

void FragTrap::attack(const std::string &target) {
	if (_hitPoint < _attackDamage)
		std::cout << "FragTrap " << _name << " doesn't have enough hit points. Attack failed" << std::endl;
	else {
		std::cout << "FragTrap " << _name << " attack " << target << ", causing " << _attackDamage<< " points of damage!" << std::endl;
		_hitPoint -= _attackDamage;
	}
}

void FragTrap::beRepaired(unsigned int amount) {
	std::cout << _name << " is repaired... Got " << amount << " of energy points..." << std::endl;
	_energyPoint += amount;
	if (_energyPoint > F_ENERGYPOINT) {
		_energyPoint = F_ENERGYPOINT;
		std::cout << "Too much energy... Energy point is " << _energyPoint << " now" << std::endl;
	}
}

void FragTrap::highFivesGuys() const {
	std::cout << "FragTrap high five guys" << std::endl;
}

void FragTrap::printStatus() const {
	std::cout << std::setw(40) << std::setfill('-') <<  _name + "'s status--------------" << std::setfill(' ') << std::endl;
	std::cout << std::setw(25) << "name: " << _name << std::endl;
	std::cout << std::setw(25) << "hit point: " << _hitPoint << std::endl;
	std::cout << std::setw(25) << "energy point: " << _energyPoint << std::endl;
	std::cout << std::setw(25) << "attack damage: " << _attackDamage<< std::endl;
	highFivesGuys();
	std::cout << std::setw(40) << std::setfill('-') << "-" << std::endl << std::endl;
	std::setfill(' ');
}

FragTrap::FragTrap() : ClapTrap("") {
	_hitPoint = F_HITPOINT;
	_energyPoint = F_ENERGYPOINT;
	_attackDamage = F_ATTACKDAMAGE;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string name): ClapTrap(name) {
	_hitPoint = F_HITPOINT;
	_energyPoint = F_ENERGYPOINT;
	_attackDamage = F_ATTACKDAMAGE;
	std::cout << "FragTrap constructor with name \"" << _name << "\" called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &origin): ClapTrap(origin) {
	*this = origin;
}

FragTrap& FragTrap::operator=(const FragTrap &origin) {
	ClapTrap::operator=(origin);
	return (*this);
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << _name << "'s destructor called" << std::endl;
}
