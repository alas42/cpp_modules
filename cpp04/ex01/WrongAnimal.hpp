#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>
# define RESET "\033[0m"
# define GREEN "\033[32m"
# define MAGENTA "\033[35m"
# define RED "\033[31m"

class WrongAnimal
{
	public :
		/*
		** Canonical Form
		*/
		WrongAnimal(void);
		~WrongAnimal(void);
		WrongAnimal(WrongAnimal const & other);
		WrongAnimal & operator = (WrongAnimal const & other);

		/*
		** Other constructors
		*/
		WrongAnimal(std::string const & species);

		/*
		** Misc
		*/
		void makeSound(void) const;
		/*
		** Guetters and setters
		*/
		std::string	const & getType(void) const;

	protected :
		std::string type;
	
};

#endif
