#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>
# include <iostream>

class Weapon
{
	public:
		Weapon(std::string const & type);
		~Weapon(void);
		std::string const &	getType(void) const;
		void				setType(std::string const & type);

	private:
		Weapon(void);
		std::string _type;
};

#endif
