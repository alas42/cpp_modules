#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>
# define RESET "\033[0m"
# define GREEN "\033[32m"
# define MAGENTA "\033[35m"
# define RED "\033[31m"

class Animal
{
	public :
		/*
		** Canonical Form
		*/
		Animal(void);
		virtual ~Animal(void);
		Animal(Animal const & other);
		Animal & operator = (Animal const & other);

		/*
		** Other constructors
		*/
		Animal(std::string const & species);
		/*
		** Misc
		*/
		virtual void makeSound(void) const = 0;
		/*
		** Guetters and setters
		*/
		std::string	const & getType(void) const;

	protected :
		std::string type;
	
};

#endif
