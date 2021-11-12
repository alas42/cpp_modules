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
		/*
		** Misc
		*/
		void whoAmI(void) const;

		/*
		** Guetters and setters
		*/

	private :
		std::string _name;
};

#endif
