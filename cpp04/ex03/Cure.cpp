#include "Cure.hpp"

/*
** Canonical Form
*/
Cure::Cure(void): AMateria("cure")
{
	std::cout << GREEN << "Cure got created." << RESET << std::endl;
}

Cure::Cure(Cure const & other): AMateria(other)
{
	*this = other;
	std::cout << GREEN << "Cure got created thank another." << RESET << std::endl;
}

Cure::~Cure(void)
{
	std::cout << RED << "Cure got destroyed." << RESET << std::endl;
}

Cure & Cure::operator = (Cure const & other)
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
AMateria * Cure::clone(void) const
{
	Cure * newCure = new Cure(*this);
	return newCure;
}

void Cure::use(ICharacter & target)
{
	std::cout << "* heals " << target.getName() << " wounds *" << std::endl;
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
