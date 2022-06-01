#include "ScavTrap.hpp"

void ScavTrap::attack(const std::string &target) {
	if (_hitPoint < _attackDamage)
		std::cout << "ScavTrap " << _name << " doesn't have enough hit points. Attack failed" << std::endl;
	else {
		std::cout << "ScavTrap " << _name << " attack " << target << ", causing " << _attackDamage<< " points of damage!" << std::endl;
		_hitPoint -= _attackDamage;
	}
}

void ScavTrap::beRepaired(unsigned int amount) {
	std::cout << _name << " is repaired... Got " << amount << " of energy points..." << std::endl;
	_energyPoint += amount;
	if (_energyPoint > S_ENERGYPOINT) {
		_energyPoint = S_ENERGYPOINT;
		std::cout << "Too much energy... Energy point is " << _energyPoint << " now" << std::endl;
	}
}

bool ScavTrap::getGuardMode() const {
	return _guardMode;
}

void ScavTrap::guardGate() const {
	std::cout << "ScavTrap [GATE KEEPER MODE] " << (_guardMode == true ? "on" : "off") << std::endl;
}

void ScavTrap::printStatus() const {
	std::cout << std::setw(40) << std::setfill('-') << _name + "'s status--------------" << std::setfill(' ') << std::endl;
	std::cout << std::setw(25) << "name: " << _name << std::endl;
	std::cout << std::setw(25) << "hit point: " << _hitPoint << std::endl;
	std::cout << std::setw(25) << "energy point: " << _energyPoint << std::endl;
	std::cout << std::setw(25) << "attack damage: " << _attackDamage<< std::endl;
	guardGate();
	std::cout << std::setw(40) << std::setfill('-') << "-" << std::endl << std::endl;
	std::setfill(' ');
}

ScavTrap::ScavTrap() : ClapTrap(""), _guardMode(false) {
	_hitPoint = S_HITPOINT;
	_energyPoint = S_ENERGYPOINT;
	_attackDamage = S_ATTACKDAMAGE;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string name): ClapTrap(name), _guardMode(false) {
	_hitPoint = S_HITPOINT;
	_energyPoint = S_ENERGYPOINT;
	_attackDamage = S_ATTACKDAMAGE;
	std::cout << "ScavTrap constructor with name \"" << _name << "\" called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &origin): ClapTrap(origin) {
	*this = origin;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &origin) {
	ClapTrap::operator=(origin);
	_guardMode = origin._guardMode;
	return (*this);
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << _name << "'s destructor called" << std::endl;
}
