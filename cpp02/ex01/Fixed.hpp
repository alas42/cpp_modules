#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed
{
	public:
		Fixed(void);
		~Fixed(void);
		Fixed(Fixed const &object);
		Fixed(int const n);
		Fixed(float const f);
		Fixed& operator = (Fixed const &other);

		float	toFloat(void) const;
		int		toInt(void) const;
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
	
	private:
		int	_fixed;
		static int const _nb_bits = 8;
};

std::ostream& operator << (std::ostream& os, Fixed const &fixed);

#endif
