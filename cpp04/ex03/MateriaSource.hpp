#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "AMateria.hpp"
# include "IMateriaSource.hpp"
# include <string>
# include <iostream>
# define RESET "\033[0m"
# define GREEN "\033[32m"
# define MAGENTA "\033[35m"
# define RED "\033[31m"

class MateriaSource: public IMateriaSource
{
	public :
		/*
		** Canonical Form
		*/
		MateriaSource(void);
		~MateriaSource(void);
		MateriaSource(MateriaSource const & other);
		MateriaSource & operator = (MateriaSource const & other);

		/*
		** Other constructors
		*/
		/*
		** Misc
		*/
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
		/*
		** Guetters and setters
		*/
	private :
		AMateria * _materia_templates[4];
};

#endif
