#include "A.hpp"

/*
** Canonical Form
*/
A::A(void)
{
	std::cout << GREEN << "A got created." << RESET << std::endl;
}

A::A(A const & other)
{
	*this = other;
	std::cout << GREEN << "A got created thank another." << RESET << std::endl;
}

A::~A(void)
{
	std::cout << RED << "A got destroyed." << RESET << std::endl;
}

A & A::operator = (A const & other)
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
