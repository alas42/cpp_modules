#ifndef A_HPP
# define A_HPP

# include <string>
# include <iostream>
# include "Base.hpp"

# define RESET "\033[0m"
# define GREEN "\033[32m"
# define MAGENTA "\033[35m"
# define RED "\033[31m"

class A: public Base
{
	public :
		/*
		** Canonical Form
		*/
		A(void);
		~A(void);
		A(A const & other);
		A & operator = (A const & other);

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
