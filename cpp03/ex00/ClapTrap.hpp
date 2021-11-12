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
	
	private:
		std::string 	_name;
		unsigned int	_hit_points;
		int				_energy_points;
		int				_attack_damage;
};

#endif
