#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include <string>
# include <iostream>
# define RESET "\033[0m"
# define GREEN "\033[32m"
# define MAGENTA "\033[35m"
# define RED "\033[31m"

class Cure : public AMateria
{
	public :
		/*
		** Canonical Form
		*/
		Cure(void);
		~Cure(void);
		Cure(Cure const & other);
		Cure & operator = (Cure const & other);
		/*
		** Other constructors
		*/
		Cure(std::string const & type);
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
