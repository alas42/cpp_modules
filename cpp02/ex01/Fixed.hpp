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
		float	toFloat(void) const;
		int		toInt(void) const;

		/*
		** Guetters and setters
		*/
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		/*
		** Operators overload
		*/
		Fixed & operator = (Fixed const & other);

	private:
		int					_fixed;
		static int const	_nb_bits = 8;
};

std::ostream & operator << (std::ostream & os, Fixed const & fixed);

#endif
