#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {};

HumanB::~HumanB()
{

};

void HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
};

void HumanB::attack()
{
	if (_weapon)
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
};
