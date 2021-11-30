#ifndef FIRE_HPP
# define FIRE_HPP

# include "AMateria.hpp"
# include <string>
# include <iostream>
# define RESET "\033[0m"
# define GREEN "\033[32m"
# define MAGENTA "\033[35m"
# define RED "\033[31m"

class Fire: public AMateria
{
	public :
		/*
		** Canonical Form
		*/
		Fire(void);
		~Fire(void);
		Fire(Fire const & other);
		Fire & operator = (Fire const & other);

		/*
		** Other constructors
		*/
		Fire(std::string const & type);
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
