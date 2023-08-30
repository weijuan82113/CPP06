#ifndef HUMANB_HPP
 #define HUMANB_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(std::string name);
		~HumanB();
		void setWeapon(Weapon& weapon);
		void attack();

	private:
		std::string _name;
		Weapon *_weapon;
};

#endif
