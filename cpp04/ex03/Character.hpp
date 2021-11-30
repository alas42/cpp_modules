#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"
# include <string>
# include <iostream>
# define RESET "\033[0m"
# define GREEN "\033[32m"
# define MAGENTA "\033[35m"
# define RED "\033[31m"

class Character : public ICharacter
{
	public :
		/*
		** Canonical Form
		*/
		Character(void);
		~Character(void);
		Character(Character const & other);
		Character & operator = (Character const & other);

		/*
		** Other constructors
		*/
		Character(std::string const & name);
		/*
		** Misc
		*/
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		/*
		** Guetters and setters
		*/
		std::string const & getName() const;

	private :
		AMateria *	_inventory[4];
		std::string _name;
};

#endif
