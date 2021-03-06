#include "Fixed.hpp"

/*
** Canonical form
*/
Fixed::Fixed(void): _fixed(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & object)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_fixed = object.getRawBits();
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}
/*
** End of canonical form
*/

/*
** Guetters and setters
*/
int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixed;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixed = raw;
}
/*
** End of guetters and setters
*/

/*
** Operators overloads
*/
Fixed & Fixed::operator = (Fixed const & other)
{
	std::cout << "Assignation operator called" << std::endl;
	if (&other != this)
		this->_fixed = other.getRawBits();
	return *this;
}
/*
** End of operators overlaods
*/
