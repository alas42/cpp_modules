#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <string>
# include <iomanip>
# include "ClapTrap.hpp"

class FragTrap: public virtual ClapTrap
{
	public:
		/*
		** Canonical Form
		*/
		FragTrap(void);
		FragTrap(FragTrap const & other);
		~FragTrap(void);
		FragTrap & operator = (FragTrap const & other);
		/*
		** Other Constructors
		*/
		FragTrap(std::string name);
		
		/*
		** Misc
		*/
		void	highFivesGuys(void);		
};

#endif