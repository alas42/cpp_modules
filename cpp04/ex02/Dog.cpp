#include "Dog.hpp"

/*
** Canonical Form
*/
Dog::Dog(void): Animal("Dog")
{	
	this->brain = new Brain();
	std::cout << GREEN << "The Dog (type: " << this->type << ") is born naturally." << RESET << std::endl;
}

Dog::Dog(Dog const & other): Animal(other)
{
	this->brain = 0;
	*this = other;
	std::cout << GREEN << "The Dog (type: " << this->type << ") is born from a copy." << RESET << std::endl;
}

Dog::~Dog(void)
{
	delete this->brain;
	std::cout << RED << "The Dog (type: " << this->type << ") is destroyed." << RESET << std::endl;
}

Dog & Dog::operator = (Dog const & other)
{
	if (this == &other)
		return *this;
	if (this->brain != 0)
		delete this->brain;
	this->brain = new Brain(*other.getBrain());
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
Brain * Dog::getBrain(void) const
{
	return this->brain;
}
/*
** End of Guetters and Setters
*/
