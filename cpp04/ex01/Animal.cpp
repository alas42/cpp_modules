#include "Animal.hpp"

/*
** Canonical Form
*/
Animal::Animal(void): type("Animal")
{
	std::cout << GREEN << "The Animal (type: " << this->type << ") is born naturally." << RESET << std::endl;
}

Animal::Animal(Animal const & other)
{
	*this = other;
	std::cout << GREEN << "The Animal (type: " << this->type << ") is born from a copy." << RESET << std::endl;
}

Animal::~Animal(void)
{
	std::cout << RED << "The Animal (type: " << this->type << ") is destroyed." << RESET << std::endl;
}

Animal & Animal::operator = (Animal const & other)
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
Animal::Animal(std::string const & species)
{
	this->type = species;
	std::cout << GREEN << "The Animal (type: " << this->type << ") is born." << std::endl;
}
/*
** End of Other Constructors
*/

/*
** Misc
*/
void	Animal::makeSound(void) const
{
	std::cout << "*ANIMAL SOUND*" << std::endl;
}
/*
** End of Misc
*/

/*
** Guetters and Setters
*/
std::string	const & Animal::getType(void) const
{
	return this->type;
}
/*
** End of Guetters and Setters
*/
