#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iomanip>
#include <string>

class DiamondTrap : public FragTrap, public ScavTrap
{
	public :
		/*
		** Canonical Form
		*/
		DiamondTrap(void);
		~DiamondTrap(void);
		DiamondTrap(DiamondTrap const & other);
		DiamondTrap & operator = (DiamondTrap const & other);

		/*
		** Other constructors
		*/
		DiamondTrap(std::string name);
	
		/*
		** Misc
		*/
		void whoAmI(void) const;
		void attack(std::string const & target);
		/*
		** Guetters and setters
		*/

	private :
		std::string _name;
};

#endif
