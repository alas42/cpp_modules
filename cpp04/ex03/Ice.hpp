#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include <string>
# include <iostream>
# define RESET "\033[0m"
# define GREEN "\033[32m"
# define MAGENTA "\033[35m"
# define RED "\033[31m"

class Ice : public AMateria
{
	public :
		/*
		** Canonical Form
		*/
		Ice(void);
		~Ice(void);
		Ice(Ice const & other);
		Ice & operator = (Ice const & other);
		/*
		** Other constructors
		*/
		Ice(std::string const & type);
		/*
		** Misc
		*/
		AMateria * clone(void) const;
		void use(ICharacter & target);
		/*
		** Guetters and setters
		*/
};

#endif
