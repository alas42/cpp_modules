#include "Cat.hpp"

/*
** Canonical Form
*/
Cat::Cat(void): Animal("Cat")
{
	std::cout << GREEN << "The Cat (type: " << this->type << ") is born naturally." << RESET << std::endl;
}

Cat::Cat(Cat const & other): Animal(other)
{
	std::cout << GREEN << "The Cat (type: " << this->type << ") is born from a copy." << RESET << std::endl;
}

Cat::~Cat(void)
{
	std::cout << RED << "The Cat (type: " << this->type << ") is destroyed." << RESET << std::endl;
}

Cat & Cat::operator = (Cat const & other)
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
/*
** End of Guetters and Setters
*/
