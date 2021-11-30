#include "WrongAnimal.hpp"

/*
** Canonical Form
*/
WrongAnimal::WrongAnimal(void): type("WrongAnimal")
{
	std::cout << GREEN << "The WrongAnimal (type: " << this->type << ") is born naturally." << RESET << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const & other)
{
	*this = other;
	std::cout << GREEN << "The WrongAnimal (type: " << this->type << ") is born from a copy." << RESET << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << RED << "The WrongAnimal (type: " << this->type << ") is destoyed." << RESET << std::endl;
}

WrongAnimal & WrongAnimal::operator = (WrongAnimal const & other)
{
	this->type = other.getType();
	return *this;
}
/*
** End of Canonical Form
*/

/*
** Other Constructors
*/
WrongAnimal::WrongAnimal(std::string const & species)
{
	this->type = species;
	std::cout << GREEN << "The WrongAnimal (type: " << this->type << ") is born." << RESET << std::endl;
}
/*
** End of Other Constructors
*/

/*
** Misc
*/
void	WrongAnimal::makeSound(void) const
{
	std::cout << "*WRONG ANIMAL NOISES*" << std::endl;
}
/*
** End of Misc
*/

/*
** Guetters and Setters
*/
std::string	const & WrongAnimal::getType(void) const
{
	return this->type;
}
/*
** End of Guetters and Setters
*/
