#include "FragTrap.hpp"

/*
** Canonical Form
*/
FragTrap::FragTrap(void): ClapTrap()
{
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
	this->_max_hit_points = this->_hit_points;
	std::cout << "A new FragTrap is naturally born called " << _name
		<< "." << std::endl;
}

FragTrap::FragTrap(FragTrap const & other): ClapTrap(other)
{
	std::cout << "A new FragTrap is born thank another called " << _name
		<< "." << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "The Super FragTrap is no more." << " May you rest in peace " << _name	<< "."
		<< std::endl;
}

FragTrap & FragTrap::operator = (FragTrap const & other)
{
	ClapTrap::operator=(other);
	std::cout << "A FragTrap just got his fonctionnalities changed, he is now called " << _name
		<< "." << std::endl;
	return *this;
}
/*
** End of Canonical Form
*/

/*
** Other Constructors
*/
FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
	this->_max_hit_points = this->_hit_points;
	std::cout << "It's a bird, it's a plane ... It's a FragTrap !"
		<< " By the way his name is " << _name << "."
		<< std::endl;
}
/*
** End of other Constructors
*/

/*
** Misc
*/
void	FragTrap::highFivesGuys(void)
{
	std::string	input;
	std::string key_words[2] = {"yes", "no"};

	std::cout << "\nFragTrap " << _name
		<< " knows he will be no more shortly after its creation."
		<< " But he is happy ? Why ?"
		<< " Because for a short moment, he will live, experience, laugh and love and be amazed of the Creation."
		<< " And do you know what he truly wants now but is too timid to ask ?"
		<< " (A high five)\n"
		<< "Do you want give him one ? (\"yes\"/\"no\")"
		<< std::endl;
	while (42)
	{
		std::getline(std::cin, input);
		if(std::cin.eof())
			std::cin.clear();
		if (!input.compare(key_words[1]))
		{
			std::cout << "You're a horrible person. Goodbye!" << std::endl;
			return ;
		}
		else if (!input.compare(key_words[0]))
		{
			std::cout << "Thank you, he really is happy." << std::endl;
			return ;
		}
	}
}
/*
** End of Misc
*/
