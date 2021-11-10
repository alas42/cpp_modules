#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->_name = name;
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	this->_max_hit_points = this->_hit_points;
	std::cout << "The Amazing ScavTrap whose name is "
		<< _name << " is born with "
		<< _hit_points << " hitpoints, "
		<< _energy_points << " energy points and "
		<< _attack_damage  << " attack damage."
		<< std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "The Amazing ScavTrap whose name is "
		<< _name << " is destroyed."
		<< std::endl; 
}

void	ScavTrap::guardGate(void)
{
	std::cout << "The ScavTrap " << _name << " has entered the GATE KEEPER MODE."
		<< std::endl;
}

void	ScavTrap::attack(std::string const & target)
{
	std::cout << "Oh My! The one and only "
		<< _name << ", a true ScavTrap,"
		<< " has attacked " << target << " with an attack damage of "
		<< _attack_damage << "!"
		<< std::endl;
}
