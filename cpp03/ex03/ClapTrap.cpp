#include "ClapTrap.hpp"

/*
** Canonical Form
*/

ClapTrap::ClapTrap(void):
	_name("default"), _hit_points(10), _energy_points(10), _attack_damage(0), _max_hit_points(10)
{
	std::cout << "A new ClapTrap is naturally born called " << _name << "."
		<< std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & other)
{
	*this = other;
	std::cout << "A new ClapTrap is born thank another called " << _name << "."
		<< std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "The ClapTrap called " << _name << " is destroyed."
		<< std::endl;
}

ClapTrap & ClapTrap::operator = (ClapTrap const & other)
{
	this->_name = other._name;
	this->_hit_points = other._hit_points;
	this->_energy_points = other._energy_points;
	this->_attack_damage = other._attack_damage;
	this->_max_hit_points = other._max_hit_points;
	std::cout << "A ClapTrap just got his fonctionnalities changed, he is now called " << _name << "."
		<< std::endl;
	return *this;
}
/*
** End of Canonical Form
*/

/*
** Other Constructors
*/
ClapTrap::ClapTrap(std::string name):
	_name(name), _hit_points(10), _energy_points(0), _attack_damage(0), _max_hit_points(10)
{
	std::cout << "A new ClapTrap is born called " << _name << "."
		<< std::endl;
}
/*
** End of Other Constructors
*/

/*
** Misc
*/
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
	if (_hit_points == this->_getMaxHitPoints())
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
		if (amount + _hit_points >= this->_getMaxHitPoints())
			hp_gained = this->_getMaxHitPoints() - _hit_points;
		_hit_points += hp_gained;
		std::cout << "The Claptrap " << _name
			<< " is being repaired, he gains "
			<< hp_gained
			<< " hitpoints. He now has a wooping "
			<< _hit_points << " hitpoints pool."
			<< std::endl;
	}
}
/*
** End of Misc
*/

/*
** Guetters and setters
*/
unsigned int	ClapTrap::_getMaxHitPoints(void)
{
	return this->_max_hit_points;
}
/*
** End of guetters and setters
*/
