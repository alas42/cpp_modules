#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"
# define RESET "\033[0m"
# define GREEN "\033[32m"
# define MAGENTA "\033[35m"
# define RED "\033[31m"

class Cat : public Animal
{
	public :
		/*
		** Canonical Form
		*/
		Cat(void);
		~Cat(void);
		Cat(Cat const & other);
		Cat & operator = (Cat const & other);

		/*
		** Other constructors
		*/
		/*
		** Misc
		*/
		virtual void makeSound(void) const;
		/*
		** Guetters and setters
		*/
};

#endif
