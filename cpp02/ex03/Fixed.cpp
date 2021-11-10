#include "Fixed.hpp"

Fixed::Fixed(void): _fixed(0)
{}


Fixed::~Fixed(void)
{}


Fixed::Fixed(int const n)
{
	this->_fixed = n << this->_nb_bits;
}

Fixed::Fixed(float const f)
{
	this->_fixed = (int)(roundf(f * (1 << this->_nb_bits)));
}

Fixed::Fixed(Fixed const &object)
{
	this->_fixed = object.getRawBits();
}

Fixed& Fixed::operator = (Fixed const &other)
{
	if (&other != this)
		this->_fixed = other.getRawBits();
	return *this;
}

bool Fixed::operator < (Fixed const &other) const
{	return this->_fixed < other.getRawBits(); }

bool Fixed::operator > (Fixed const &other) const
{	return this->_fixed > other.getRawBits(); }

bool Fixed::operator <= (Fixed const &other) const
{	return this->_fixed <= other.getRawBits(); }

bool Fixed::operator >= (Fixed const &other) const
{	return this->_fixed >= other.getRawBits(); }

bool Fixed::operator == (Fixed const &other) const
{	return this->_fixed == other.getRawBits(); }

bool Fixed::operator != (Fixed const &other) const
{	return this->_fixed != other.getRawBits(); }

Fixed &Fixed::operator ++ (void)
{
	this->_fixed++;
	return *this;
}

Fixed &Fixed::operator -- (void)
{
	this->_fixed--;
	return *this;
}

Fixed Fixed::operator ++ (int)
{
	Fixed	temp = *this;
	++*this;
	return temp;
}

Fixed Fixed::operator -- (int)
{
	Fixed	temp = *this;
	--*this;
	return temp;
}

Fixed Fixed::operator * (Fixed const &other)
{
	Fixed	new_fixed;

	new_fixed.setRawBits(this->_fixed * other.getRawBits());
	return new_fixed;
}

Fixed Fixed::operator + (Fixed const &other)
{
	Fixed	new_fixed;

	new_fixed.setRawBits(this->_fixed + other.getRawBits());
	return new_fixed;
}

Fixed Fixed::operator / (Fixed const &other)
{
	Fixed	new_fixed;
	int		denom = other.getRawBits();

	if (denom != 0)
		new_fixed.setRawBits(this->_fixed / other.getRawBits());
	else
		new_fixed.setRawBits(0);
	return new_fixed;
}

Fixed Fixed::operator - (Fixed const &other)
{
	Fixed	new_fixed;

	new_fixed.setRawBits(this->_fixed - other.getRawBits());
	return new_fixed;
}

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

int		Fixed::getRawBits(void) const
{
	return this->_fixed;
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixed = raw;
}
 
Fixed &min(Fixed &a, Fixed &b)
{
	if (a < b)
		return a;
	return b;
}

Fixed &max(Fixed &a, Fixed &b)
{
	if (a > b)
		return a;
	return b;
}

const Fixed &min(Fixed const &a, Fixed const &b)
{
	if (a > b)
		return a;
	return b;
}

const Fixed &max(Fixed const &a, Fixed const &b)
{
	if (a > b)
		return a;
	return b;
}

std::ostream& operator << (std::ostream& os, Fixed const &fixed)
{
	os << fixed.toFloat();
	return os;
}
