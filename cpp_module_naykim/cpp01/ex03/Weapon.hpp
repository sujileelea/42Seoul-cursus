#ifndef __WEAPON_H__
#define __WEAPON_H__

#include <string>

class Weapon {
private:
	std::string type;
public:
	Weapon();
	Weapon(std::string type);
	const std::string& getType() const;
	void setType(std::string type);
	~Weapon();
};

#endif