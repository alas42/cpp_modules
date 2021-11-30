#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "ICharacter.hpp"
# include <string>
# include <iostream>
# define RESET "\033[0m"
# define GREEN "\033[32m"
# define MAGENTA "\033[35m"
# define RED "\033[31m"

class ICharacter;

class AMateria
{
	public :
		/*
		** Canonical Form
		*/
		AMateria(void);
		virtual ~AMateria(void);
		AMateria(AMateria const & other);
		AMateria & operator = (AMateria const & other);
		/*
		** Other constructors
		*/
		AMateria(std::string const & type);
		/*
		** Misc
		*/
		virtual AMateria * clone(void) const = 0;
		virtual void use(ICharacter & target);
		/*
		** Guetters and setters
		*/
		std::string const & getType(void) const;

	protected :
		std::string type;
};

#endif
