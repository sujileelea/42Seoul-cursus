#include "ClapTrap.hpp"

void ClapTrap::attack(const std::string &target) {
	if (_hitPoint < _attackDamage)
		std::cout << "ClapTrap " << _name << " doesn't have enough hit points. Attack failed" << std::endl;
	else {
		std::cout << "ClapTrap " << _name << " attack " << target << ", causing " << _attackDamage<< " points of damage!" << std::endl;
		_hitPoint -= _attackDamage;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	std::cout << _name << " is attacked! " << amount << " of damages!" << std::endl;
	_energyPoint -= std::min(amount, _energyPoint);
}

void ClapTrap::beRepaired(unsigned int amount) {
	std::cout << _name << " is repaired... Got " << amount << " of energy points..." << std::endl;
	_energyPoint += amount;
	if (_energyPoint > C_ENERGYPOINT) {
		_energyPoint = C_ENERGYPOINT;
		std::cout << "Too much energy... Energy point is " << _energyPoint << " now" << std::endl;
	}
}

std::string ClapTrap::getName() const {
	return _name;
}

unsigned int ClapTrap::getHit() const {
	return _hitPoint;
}

unsigned int ClapTrap::getEp() const {
	return _energyPoint;
}

unsigned int ClapTrap::getAd() const {
	return _attackDamage;
}

void ClapTrap::setName(const std::string &name) {
	_name = name;
}

void ClapTrap::setHit(unsigned int hit) {
	_hitPoint = hit;
}

void ClapTrap::setEp(unsigned int energyPoint) {
	_energyPoint = energyPoint;
}

void ClapTrap::setAd(unsigned int attackDamage) {
	_attackDamage= attackDamage;
}

void ClapTrap::printStatus() const {
	std::cout << std::setw(40) << std::setfill('-') <<  _name + "'s status--------------" << std::setfill(' ') << std::endl;
	std::cout << std::setw(25) << "name: " << _name << std::endl;
	std::cout << std::setw(25) << "hit point: " << _hitPoint << std::endl;
	std::cout << std::setw(25) << "energy point: " << _energyPoint << std::endl;
	std::cout << std::setw(25) << "attack damage: " << _attackDamage<< std::endl;
	std::cout << std::setw(40) << std::setfill('-') << "-" << std::endl << std::endl;
	std::setfill('-');
}

ClapTrap::ClapTrap(): _name(""), _hitPoint(C_HITPOINT), _energyPoint(C_ENERGYPOINT), _attackDamage(C_ATTACKDAMAGE) {
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoint(C_HITPOINT), _energyPoint(C_ENERGYPOINT), _attackDamage(C_ATTACKDAMAGE) {
	std::cout << "ClapTrap constructor with name \"" << name << "\" called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &origin) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = origin;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& origin) {
	_name = origin.getName();
	_hitPoint = origin.getHit();
	_energyPoint = origin.getEp();
	_attackDamage = origin.getAd();
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << _name << "'s destructor called" << std::endl;
}