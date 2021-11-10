#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

# include "Weapon.hpp"
# include <string>
# include <iostream>

class HumanB
{
	public:
		HumanB(std::string const & name);
		~HumanB(void);
		void	attack(void) const;
		void	setWeapon(Weapon& weapon);

	private:
		HumanB(void);
		Weapon*			_weapon;
		std::string		_name;
};

#endif
