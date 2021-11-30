#include "Ice.hpp"

/*
** Canonical Form
*/
Ice::Ice(void): AMateria("ice")
{
	std::cout << GREEN << "Ice got created." << RESET << std::endl;
}

Ice::Ice(Ice const & other): AMateria(other)
{
	*this = other;
	std::cout << GREEN << "Ice got created thank another." << RESET << std::endl;
}

Ice::~Ice(void)
{
	std::cout << RED << "Ice got destroyed." << RESET << std::endl;
}

Ice & Ice::operator = (Ice const & other)
{
	if (this != &other)
		AMateria::operator=(other);
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
AMateria * Ice::clone(void) const
{
	Ice * newCure = new Ice(*this);
	return newCure;
}

void Ice::use(ICharacter & target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
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
