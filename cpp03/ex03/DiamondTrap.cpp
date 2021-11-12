#include "DiamondTrap.hpp"

/*
** Canonical Form
*/
DiamondTrap::DiamondTrap(void): ClapTrap("John_Doe_clap_name"), FragTrap(), ScavTrap()
{
	this->_name = "John_Doe";
	this->_attack_damage = 30;
	this->_energy_points = 50;
	this->_max_hit_points = this->_hit_points;
	std::cout << "A new DiamondTrap is naturally born called " << _name
		<< "." << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const & other)
{
	*this = other;
	std::cout << "A new DiamondTrap is born thank another called " << _name
		<< "." << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "The shiny DiamondTrap " << _name << " lost his luster." << std::endl;
}

DiamondTrap & DiamondTrap::operator = (DiamondTrap const & other)
{
	ClapTrap::_name = other._name + "_clap_name";
	this->_name = other._name;
	this->_attack_damage = other._attack_damage;
	this->_energy_points = other._energy_points;
	this->_hit_points = other._hit_points;
	this->_max_hit_points = other._max_hit_points;
	return *this;
}
/*
** End of Canonical Form
*/

/*
** Other Constructors
*/
DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
	this->_name = name;
	this->_attack_damage = 30;
	this->_energy_points = 50;
	this->_max_hit_points = this->_hit_points;
	std::cout << "A new DiamondTrap is born called " << _name
		<< "." << std::endl;

}
/*
** End of Other Constructors
*/

/*
** Misc
*/
void	DiamondTrap::whoAmI(void) const
{
	std::cout << "Its Claptrap name is : " << ClapTrap::_name
		<<"\nIts DiamonTrap name is : " << this->_name << std::endl;
}

void	DiamondTrap::attack(std::string const & target)
{
	ScavTrap::attack(target);
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
