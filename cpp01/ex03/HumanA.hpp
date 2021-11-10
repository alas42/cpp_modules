#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

# include "Weapon.hpp"
# include <string>
# include <iostream>

class HumanA
{
	public:
		HumanA(std::string const & name, Weapon& weapon);
		~HumanA(void);
		void	attack(void) const;

	private:
		HumanA(void);
		std::string		_name;
		Weapon& 		_weapon;
};

#endif
