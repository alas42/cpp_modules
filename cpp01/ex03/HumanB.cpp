#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name)
{
	this->_weapon = 0;
}

HumanB::~HumanB(void)
{}

void	HumanB::attack(void) const
{
	if (this->_weapon != 0)
	{
		std::string weapon_type = this->_weapon->getType();
		std::cout << this->_name << " attacks with his ";
		std::cout << weapon_type <<  std::endl;
	}
	else
	{
		std::cout << this->_name << " can't attack because he has no weapon" << std::endl;
	}
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
}
