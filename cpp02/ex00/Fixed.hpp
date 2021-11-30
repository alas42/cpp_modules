#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
	public:
		/*
		** Canonical form
		*/
		Fixed(void);
		~Fixed(void);
		Fixed(Fixed const &object);

		/*
		** Guetters and setters
		*/
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		/*
		** Operators overload
		*/
		Fixed& operator = (Fixed const &other);
	
	private:
		int					_fixed;
		static int const	_nb_bits = 8;
};

#endif