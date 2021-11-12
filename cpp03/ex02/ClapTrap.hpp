#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>

class ClapTrap
{
	public:
		/*
		** Canonical Form
		*/
		ClapTrap(void);
		ClapTrap(ClapTrap const & other);
		~ClapTrap(void);
		ClapTrap & operator = (ClapTrap const &  other);

		/*
		** Other Constructors
		*/
		ClapTrap(std::string name);
		
		/*
		** Misc
		*/
		void	attack(std::string const & target);
		void 	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

	protected:
		std::string 		_name;
		unsigned int		_hit_points;
		int					_energy_points;
		int					_attack_damage;
		unsigned int 		_max_hit_points;
		unsigned int		_getMaxHitPoints(void);

};

#endif
