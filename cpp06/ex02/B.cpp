#include "B.hpp"

/*
** Canonical Form
*/
B::B(void)
{
	std::cout << GREEN << "B got created." << RESET << std::endl;
}

B::B(B const & other)
{
	*this = other;
	std::cout << GREEN << "B got created thank another." << RESET << std::endl;
}

B::~B(void)
{
	std::cout << RED << "B got destroyed." << RESET << std::endl;
}

B & B::operator = (B const & other)
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
