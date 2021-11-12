#include "DiamondTrap.hpp"

/*
** Canonical Form
*/
DiamondTrap::DiamondTrap(void): FragTrap(), ScavTrap()
{
	this->_attack_damage = 20;
	this->_energy_points = 100;
	this->_max_hit_points = this->_hit_points;
}

DiamondTrap::DiamondTrap(DiamondTrap const & other)
{
	*this = other;
}

DiamondTrap::~DiamondTrap(void)
{}

DiamondTrap & DiamondTrap::operator = (DiamondTrap const & other)
{
	return *this;
}
/*
** End of Canonical Form
*/

/*
** Other Constructors
*/
/*
** End of Other Constructors
*/

/*
** Misc
*/
void	DiamondTrap::whoAmI(void) const
{
	std::cout << "It's Claptrap name is : It's DiamonTrap name is : " << this->_name << std::endl;
}
/*
** End of Misc
*/

/*
** Guetters and Setters
*/
/*
** End of Guetters and Setters
*/
