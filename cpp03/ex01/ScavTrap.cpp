#include "ScavTrap.hpp"

/*
** Canonical Form
*/
ScavTrap::ScavTrap(void): ClapTrap()
{
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	this->_max_hit_points = this->_hit_points;
	std::cout << "A new ScavTrap is naturally born called " << _name
		<< "." << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & other): ClapTrap(other)
{
	std::cout << "A new ScavTrap is born thank another called " << _name
		<< "." << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "The Amazing ScavTrap whose name is " << _name << " is destroyed."
		<< std::endl; 
}

ScavTrap & ScavTrap::operator = (ScavTrap const & other)
{
	ClapTrap::operator=(other);
	std::cout << "A ScavTrap just got his fonctionnalities changed, he is now called " << _name
		<< "." << std::endl;
	return *this;
}
/*
** End of Canonical Form
*/

/*
** Other Constructors
*/
ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	this->_max_hit_points = this->_hit_points;
	std::cout << "The Amazing ScavTrap whose name is " << _name << " is born." << std::endl;
}
/*
** End of Other Constructors
*/

/*
** Misc
*/
void	ScavTrap::guardGate(void)
{
	std::cout << "The ScavTrap " << _name << " has entered the GATE KEEPER MODE."
		<< std::endl;
}

void	ScavTrap::attack(std::string const & target)
{
	if (this->_energy_points > 0)
	{
		this->_energy_points -= 1;
		std::cout << "Oh My! The one and only " << _name << ", a true ScavTrap,"
			<< " has attacked " << target << " with an attack damage of " << _attack_damage << "!"
			<< " (-1 energy point)"
			<< std::endl;
	}
	else
	{
		std::cout << "Oh My! The one and only " << _name << ", a true ScavTrap,"
			<< " wants to attack " << target << " but cannot, he has " << this->_energy_points
			<< " energy points!"
			<< std::endl;
	}
}
/*
** End of Misc
*/
