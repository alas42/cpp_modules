#include "Fixed.hpp"

/*
** Canonical form
*/
Fixed::Fixed(void): _fixed(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	//std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const & object)
{
	//std::cout << "Copy constructor called" << std::endl;
	this->_fixed = object.getRawBits();
}
/*
** End of Canonical form
*/

/*
** Other constructors
*/
Fixed::Fixed(int const n)
{
	//std::cout << "Int constructor called" << std::endl;
	this->_fixed = n << this->_nb_bits;
}

Fixed::Fixed(float const f)
{
	//std::cout << "Float constructor called" << std::endl;
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

Fixed const & Fixed::min(Fixed const & a, Fixed const & b)
{
	if (a < b)
		return a;
	return b;
}

Fixed const & Fixed::max(Fixed const & a, Fixed const & b)
{
	if (a > b)
		return a;
	return b;
}

Fixed const & min(Fixed const & a, Fixed const & b)
{
	if (a < b)
		return a;
	return b;
}

Fixed const & max(Fixed const & a, Fixed const & b)
{
	if (a > b)
		return a;
	return b;
}
/*
** End of misc
*/

/*
** Operators overloads
*/
Fixed & Fixed::operator = (Fixed const & other)
{
	//std::cout << "Assignation operator called" << std::endl;
	if (&other != this)
		this->_fixed = other.getRawBits();
	return *this;
}

bool Fixed::operator < (Fixed const & other) const
{	return this->_fixed < other.getRawBits(); }

bool Fixed::operator > (Fixed const & other) const
{	return this->_fixed > other.getRawBits(); }

bool Fixed::operator <= (Fixed const & other) const
{	return this->_fixed <= other.getRawBits(); }

bool Fixed::operator >= (Fixed const & other) const
{	return this->_fixed >= other.getRawBits(); }

bool Fixed::operator == (Fixed const & other) const
{	return this->_fixed == other.getRawBits(); }

bool Fixed::operator != (Fixed const & other) const
{	return this->_fixed != other.getRawBits(); }

Fixed & Fixed::operator ++ (void)
{
	this->_fixed++;
	return *this;
}

Fixed & Fixed::operator -- (void)
{
	this->_fixed--;
	return *this;
}

Fixed Fixed::operator ++ (int)
{
	Fixed	temp = *this;
	++(*this);
	return temp;
}

Fixed Fixed::operator -- (int)
{
	Fixed	temp = *this;
	--(*this);
	return temp;
}

Fixed Fixed::operator * (Fixed const & other)
{
	Fixed	new_fixed;

	new_fixed.setRawBits(this->toFloat() * other.getRawBits());
	return new_fixed;
}

Fixed Fixed::operator + (Fixed const & other)
{
	Fixed	new_fixed;

	new_fixed.setRawBits(this->_fixed + other.getRawBits());
	return new_fixed;
}

Fixed Fixed::operator / (Fixed const & other)
{
	Fixed	new_fixed;
	int		denom = other.getRawBits();

	if (denom != 0)
	{
		new_fixed.setRawBits(roundf(1 << this->_nb_bits)
			* this->getRawBits() / other.getRawBits());
	}
	else
	{
		std::cout << "Foolish choice to divide by 0, the value will be set to zero" << std::endl;
		new_fixed.setRawBits(0);
	}
	return new_fixed;
}

Fixed Fixed::operator - (Fixed const & other)
{
	Fixed	new_fixed;

	new_fixed.setRawBits(this->_fixed - other.getRawBits());
	return new_fixed;
}

std::ostream & operator << (std::ostream & os, Fixed const & fixed)
{
	os << fixed.toFloat();
	return os;
}
/*
** End of operators overloads
*/

/*
** Guetters an setters
*/
int		Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return this->_fixed;
}

void	Fixed::setRawBits(int const raw)
{
	//std::cout << "setRawBits member function called" << std::endl;
	this->_fixed = raw;
}
/*
** End of guetters and setters
*/
