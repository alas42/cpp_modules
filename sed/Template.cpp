#include "Template.hpp"

/*
** Canonical Form
*/
Template::Template(void)
{
	std::cout << GREEN << "Template got created." << RESET << std::endl;
}

Template::Template(Template const & other)
{
	*this = other;
	std::cout << GREEN << "Template got created thank another." << RESET << std::endl;
}

Template::~Template(void)
{
	std::cout << RED << "Template got destroyed." << RESET << std::endl;
}

Template & Template::operator = (Template const & other)
{
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
