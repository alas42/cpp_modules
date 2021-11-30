#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"
# include <iostream>
# include <string>
# define RESET "\033[0m"
# define GREEN "\033[32m"
# define MAGENTA "\033[35m"
# define RED "\033[31m"

class WrongCat : public WrongAnimal
{
	public :
		/*
		** Canonical Form
		*/
		WrongCat(void);
		~WrongCat(void);
		WrongCat(WrongCat const & other);
		WrongCat & operator = (WrongCat const & other);

		/*
		** Other constructors
		*/
		/*
		** Misc
		*/
		void makeSound(void) const;
		/*
		** Guetters and setters
		*/
	
};

#endif
