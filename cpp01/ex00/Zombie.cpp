#include "Zombie.hpp"

Zombie::Zombie(std::string name): _name(name)
{
	return;
}

Zombie::~Zombie(void)
{
	std::cout  << "I, "<< this->_name << ", wanna have more BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << "<" << this->_name << "> BraiiiiiiinnnzzzZ..." << std::endl;
}
