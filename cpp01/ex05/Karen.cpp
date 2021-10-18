#include "Karen.hpp"

Karen::Karen(void)
{
	this->_func[0] = &Karen::_debug;
	this->_func[1] = &Karen::_info;
	this->_func[2] = &Karen::_warning;
	this->_func[3] = &Karen::_error;
}

Karen::~Karen(void)
{}

void	Karen::_debug(void)
{
	std::cout << "I love to get extra baconfor my 7XL-double-cheese-triple-pickle-special-ketchup burger.";
	std::cout << " I just love it!" << std::endl;
}

void	Karen::_info(void)
{
	std::cout << "I cannot believe adding extrabacon cost more money. You don’t put enough!";
	std::cout << " If you did I would not have to askfor it!" << std::endl;
}

void	Karen::_warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free.";
	std::cout << " I’ve beencoming here for years and you just started working here last month." << std::endl;
}

void	Karen::_error(void)
{
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

void	Karen::complain(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++)
	{
		if (!level.compare(levels[i]))
		{
			(this->*_func[i])();
			return ;
		}
	}
	std::cout << "level not found" << std::endl;
}
