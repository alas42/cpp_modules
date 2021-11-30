#include "WrongCat.hpp"

/*
** Canonical Form
*/
WrongCat::WrongCat(void): WrongAnimal("WrongCat")
{
	std::cout << GREEN << "The WrongCat (type: " << this->type << ") is born naturally." << RESET << std::endl;
}

WrongCat::WrongCat(WrongCat const & other): WrongAnimal(other)
{
	std::cout << GREEN << "The WrongCat(type: " << this->type << ") is born from a copy." << RESET << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << RED << "The WrongCat (type: " << this->type << ") is destoyed." << RESET << std::endl;
}

WrongCat & WrongCat::operator = (WrongCat const & other)
{
	WrongAnimal::operator=(other);
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
void	WrongCat::makeSound(void) const
{
	std::cout << "MIAOU (WRONG)" << std::endl;
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
