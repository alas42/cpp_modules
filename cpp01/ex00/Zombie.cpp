#include "Zombie.hpp"

Zombie::Zombie(void)
{}

Zombie::Zombie(std::string name): _name(name)
{}

Zombie::~Zombie(void)
{
	std::cout  << "<" << this->_name
	<< "> I wanna have more BraiiiiiiinnnzzzZ... (dead)" << std::endl;
}

void	Zombie::announce(void) const
{
	std::cout << "<" << this->_name
		<< "> BraiiiiiiinnnzzzZ..." << std::endl;
}
