#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>

class ClapTrap
{
	public:
		ClapTrap(std::string name);
		~ClapTrap(void);

		void			attack(std::string const & target);
		void 			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);

	protected:
		std::string 		_name;
		unsigned int		_hit_points;
		int					_energy_points;
		int					_attack_damage;
		unsigned int 		_max_hit_points;
		unsigned int		_getMaxHitPoints(void);
};

#endif