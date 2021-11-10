#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name):
	_name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "A new ClapTrap is born called " << _name
		<< "\nHe has "
		<< _hit_points
		<< " hitpoints, "
		<< _energy_points
		<< " energy points and "
		<< _attack_damage
		<< " attack damage." << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "The ClapTrap called " << _name << " is destroyed." << std::endl;
}

void	ClapTrap::attack(std::string const & target)
{
	std::cout << "The Claptrap with the dashing name "
		<< _name << " attacks " << target
		<< ". It deals a great " << _attack_damage << " of damage!"
		<< std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > _hit_points)
		_hit_points = 0;
	else
		_hit_points -= amount;
	if (_hit_points < 1)
	{
		std::cout << "The Great Claptrap immatriculated "
			<< _name << " has taken  " << amount << " of damage!"
			<< " His state is now beyond repair, his hitpoints reached "
			<< _hit_points << "."
			<< std::endl;
	}
	else
	{
		std::cout << "The Great Claptrap immatriculated "
			<< _name << " has taken  " << amount << " of damage!"
			<< " He has "<< _hit_points << " hitpoints left."
			<< std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	unsigned int	hp_gained;

	hp_gained = 0;
	if (_hit_points == 0)
	{
		std::cout << "The Claptrap " <<_name 
			<< " cannot be repaired. His state is beyond repair with "
			<< _hit_points << " hitpoint."
			<< std::endl;
		return ;
	}
	if (amount == 0)
	{
		std::cout << "The Claptrap " << _name
			<< " isn't going to be repaired with that. ("
			<< amount << ")."
			<< std::endl;
		return ;
	}
	if (_hit_points == 10)
	{
		std::cout << "The Claptrap " <<_name 
			<< " cannot be repaired."
			<< " His state is still undamaged with "
			<< _hit_points << " hitpoints."
			<< std::endl;
	}
	else
	{
		hp_gained = amount;
		if (amount + _hit_points >= 10)
			hp_gained = 10 - _hit_points;
		_hit_points += hp_gained;
		std::cout << "The Claptrap " << _name
			<< " is being repaired, he gains "
			<< hp_gained
			<< " hitpoints. He now has a wooping "
			<< _hit_points << " hitpoints pool."
			<< std::endl;
	}
}