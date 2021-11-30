#include "Dog.hpp"

/*
** Canonical Form
*/
Dog::Dog(void): Animal("Dog")
{	
	std::cout << GREEN << "The Dog (type: " << this->type << ") is born naturally." << RESET << std::endl;
}

Dog::Dog(Dog const & other): Animal(other)
{
	std::cout << GREEN << "The Dog (type: " << this->type << ") is born from a copy." << RESET << std::endl;
}

Dog::~Dog(void)
{
	std::cout << RED << "The Dog (type: " << this->type << ") is destroyed." << RESET << std::endl;
}

Dog & Dog::operator = (Dog const & other)
{
	Animal::operator=(other);
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
void	Dog::makeSound(void) const
{
	std::cout << "WOUF" << std::endl;
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
