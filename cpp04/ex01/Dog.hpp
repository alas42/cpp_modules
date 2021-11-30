#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"
# include "Brain.hpp"
# define RESET "\033[0m"
# define GREEN "\033[32m"
# define MAGENTA "\033[35m"
# define RED "\033[31m"

class Dog : public Animal
{
	public :
		/*
		** Canonical Form
		*/
		Dog(void);
		~Dog(void);
		Dog(Dog const & other);
		Dog & operator = (Dog const & other);

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
		Brain* getBrain(void) const; 
	
	private:
		Brain* brain;
};

#endif
