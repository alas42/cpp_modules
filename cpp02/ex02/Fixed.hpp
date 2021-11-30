#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed
{
	public:
		/*
		** Canonical form
		*/
		Fixed(void);
		~Fixed(void);
		Fixed(Fixed const & object);

		/*
		** Other constructors
		*/
		Fixed(int const n);
		Fixed(float const f);

		/*
		** Misc
		*/
		float			toFloat(void) const;
		int				toInt(void) const;
		static Fixed const &	min(Fixed const & a, Fixed const & b);
		static Fixed const & 	max(Fixed const & a, Fixed const & b);

		/*
		** Guetters and setters
		*/
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		/*
		** Operators overloads
		*/
		Fixed & operator = (Fixed const & other);
		bool operator < (Fixed const & other) const;
		bool operator > (Fixed const & other) const;
		bool operator >= (Fixed const & other) const;
		bool operator <= (Fixed const & other) const;
		bool operator == (Fixed const & other) const;
		bool operator != (Fixed const & other) const;
		Fixed operator * (Fixed const & other);
		Fixed operator / (Fixed const & other);
		Fixed operator + (Fixed const & other);
		Fixed operator - (Fixed const & other);
		Fixed & operator ++ (void);
		Fixed operator ++ (int);
		Fixed & operator -- (void);
		Fixed operator -- (int);
	
	private:
		int					_fixed;
		static int const	_nb_bits = 8;
};

std::ostream & operator << (std::ostream & os, Fixed const & fixed);
Fixed const & 	min(Fixed const & a, Fixed const & b);
Fixed const & 	max(Fixed const & a, Fixed const & b);

#endif