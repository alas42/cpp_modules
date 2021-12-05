#ifndef C_HPP
# define C_HPP

# include <string>
# include <iostream>
# include "Base.hpp"

# define RESET "\033[0m"
# define GREEN "\033[32m"
# define MAGENTA "\033[35m"
# define RED "\033[31m"

class C: public Base
{
	public :
		/*
		** Canonical Form
		*/
		C(void);
		~C(void);
		C(C const & other);
		C & operator = (C const & other);

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
