#include "Character.hpp"

/*
** Canonical Form
*/
Character::Character(void): _name("John")
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = 0;
	std::cout << GREEN << "Character " << _name << " is born." << RESET << std::endl;
}

Character::Character(Character const & other)
{
	*this = other;
	std::cout << GREEN << "Character got created thank another." << RESET << std::endl;
}

Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
		delete this->_inventory[i];
	std::cout << RED << "Character got destroyed." << RESET << std::endl;
}

Character & Character::operator = (Character const & other)
{
	if (this == &other)
		return *this;
	this->_name = other.getName();
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] != 0)
			delete this->_inventory[i];
		if (other._inventory[i] == 0)
			this->_inventory[i] = 0;
		else
			this->_inventory[i] = other._inventory[i]->clone();
	}
	return *this;
}
/*
** End of Canonical Form
*/

/*
** Other Constructors
*/
Character::Character(std::string const & name): _name(name)
{
	std::cout << GREEN << "Character " << _name << " is born." << RESET << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = 0;
}
/*
** End of Other Constructors
*/

/*
** Misc
*/
void Character::equip(AMateria* m)
{
	int i = 0;

	while (i < 4)
	{
		if (this->_inventory[i] == 0)
		{
			this->_inventory[i] = m;
			return ;
		}
		i++;
	}		
}

void Character::unequip(int idx)
{
	if (idx < 4 && idx >= 0)
	{
		this->_inventory[idx] = 0;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 4 && idx >= 0)
	{
		if (this->_inventory[idx] != 0)
		{
			this->_inventory[idx]->use(target);
			this->unequip(idx);
		}
	}
}
/*
** End of Misc
*/

/*
** Guetters and Setters
*/
std::string const & Character::getName() const
{
	return this->_name;
}

/*
** End of Guetters and Setters
*/
