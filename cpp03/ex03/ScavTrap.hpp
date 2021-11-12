#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class ScavTrap: public virtual ClapTrap
{
	public:
		/*
		** Canonical Form
		*/
		ScavTrap(void);
		ScavTrap(ScavTrap const & other);
		~ScavTrap(void);
		ScavTrap & operator = (ScavTrap const & other);

		/*
		** Other constructors
		*/
		ScavTrap(std::string name);

		/*
		** Misc
		*/
		void	guardGate(void);
		void	attack(std::string const & target);

};

#endif
