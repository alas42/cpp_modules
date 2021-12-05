#include "C.hpp"

/*
** Canonical Form
*/
C::C(void)
{
	std::cout << GREEN << "C got created." << RESET << std::endl;
}

C::C(C const & other)
{
	*this = other;
	std::cout << GREEN << "C got created thank another." << RESET << std::endl;
}

C::~C(void)
{
	std::cout << RED << "C got destroyed." << RESET << std::endl;
}

C & C::operator = (C const & other)
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
/*
** End of Other Constructors
*/

/*
** Misc
*/
/*
** End of Misc
*/

/*
** Guetters and Setters
*/
/*
** End of Guetters and Setters
*/
