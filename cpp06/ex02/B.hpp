#ifndef B_HPP
# define B_HPP

# include <string>
# include <iostream>
# include "Base.hpp"

# define RESET "\033[0m"
# define GREEN "\033[32m"
# define MAGENTA "\033[35m"
# define RED "\033[31m"

class B: public Base
{
	public :
		/*
		** Canonical Form
		*/
		B(void);
		~B(void);
		B(B const & other);
		B & operator = (B const & other);

		/*
		** Other constructors
		*/
		/*
		** Misc
		*/
		/*
		** Guetters and setters
		*/

};

#endif
