#include "Fire.hpp"

/*
** Canonical Form
*/
Fire::Fire(void): AMateria("fire")
{
	std::cout << GREEN << "Fire got created." << RESET << std::endl;
}

Fire::Fire(Fire const & other): AMateria(other)
{
	*this = other;
	std::cout << GREEN << "Fire got created thank another." << RESET << std::endl;
}

Fire::~Fire(void)
{
	std::cout << RED << "Fire got destroyed." << RESET << std::endl;
}

Fire & Fire::operator = (Fire const & other)
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
AMateria * Fire::clone(void) const
{
	Fire * newCure = new Fire(*this);
	return newCure;
}

void Fire::use(ICharacter & target)
{
	std::cout << "* burns " << target.getName() << " *" << std::endl;
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
