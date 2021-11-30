#include "AMateria.hpp"

/*
** Canonical Form
*/
AMateria::AMateria(void): type("abstract")
{
	std::cout << GREEN << "AMateria got created." << RESET << std::endl;
}

AMateria::AMateria(AMateria const & other)
{
	*this = other;
	std::cout << GREEN << "AMateria got created thank another." << RESET << std::endl;
}

AMateria::~AMateria(void)
{
	std::cout << RED << "AMateria got destroyed." << RESET << std::endl;
}

AMateria & AMateria::operator = (AMateria const & other)
{
	if (this == &other)
		return *this;
	return *this;
}
/*
** End of Canonical Form
*/

/*
** Other Constructors
*/
AMateria::AMateria(std::string const & type): type(type)
{}
/*
** End of Other Constructors
*/

/*
** Misc
*/
void AMateria::use(ICharacter & target)
{
	std::cout << "*uses an abstract Materia on "<< target.getName() << " *" << std::endl;
}
/*
** End of Misc
*/

/*
** Guetters and Setters
*/
std::string const & AMateria::getType(void) const
{
	return this->type;
}
/*
** End of Guetters and Setters
*/
