#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
	public:
		Fixed(void);
		~Fixed(void);
		Fixed(Fixed const &object);
		Fixed& operator = (Fixed const &other);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
	
	private:
		int	_fixed;
		static int const _nb_bits = 8;
};

#endif