#include "Fixed.hpp"

/*
** Canonical Form
**
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
** Other constructors
*/
Fixed::Fixed(int const n)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixed = n << this->_nb_bits;
}

Fixed::Fixed(float const f)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixed = (int)(roundf(f * (1 << this->_nb_bits)));
}
/*
** End of other constructors
*/

/*
** Misc
*/
int		Fixed::toInt(void) const
{
	int	result = this->_fixed >> this->_nb_bits;
	return result;
}

float	Fixed::toFloat(void) const
{
	float result = (float)this->_fixed / (float)(1 << this->_nb_bits);
	return result;
}
/*
** End of misc
*/

/*
** Getters and setters
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

std::ostream & operator << (std::ostream & os, Fixed const & fixed)
{
	os << fixed.toFloat();
	return os;
}
/*
** End of Operators overloads
*/
