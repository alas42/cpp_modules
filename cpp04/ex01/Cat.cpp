#include "Cat.hpp"

/*
** Canonical Form
*/
Cat::Cat(void): Animal("Cat")
{
	this->brain = new Brain();
	std::cout << GREEN << "The Cat (type: " << this->type << ") is born naturally." << RESET << std::endl;
}

Cat::Cat(Cat const & other): Animal(other)
{
	*this = other;
	std::cout << GREEN << "The Cat (type: " << this->type << ") is born from a copy." << RESET << std::endl;
}

Cat::~Cat(void)
{
	delete this->brain;
	std::cout << RED << "The Cat (type: " << this->type << ") is destroyed." << RESET << std::endl;
}

Cat & Cat::operator = (Cat const & other)
{
	if (this == &other)
		return *this;
	if (this->brain)
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
void	Cat::makeSound(void) const
{
	std::cout << "MIAOU" << std::endl;
}
/*
** End of Misc
*/

/*
** Guetters and Setters
*/
Brain * Cat::getBrain(void) const
{
	return this->brain;
}
/*
** End of Guetters and Setters
*/
