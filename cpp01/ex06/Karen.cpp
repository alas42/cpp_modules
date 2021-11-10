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
	std::cout << "[DEBUG]\n"
		<< "I love to get extra baconfor my 7XL-double-cheese-triple-pickle-special-ketchup burger."
		<< "I just love it!" << std::endl;
}

void	Karen::_info(void)
{
	std::cout << "[INFO]\n"
		<< "I cannot believe adding extrabacon cost more money. You don’t put enough!\n"
		<< "If you did I would not have to askfor it!" << std::endl;
}

void	Karen::_warning(void)
{
	std::cout << "[WARNING]\n"
		<< "I think I deserve to have some extra bacon for free.\n"
		<< "I’ve beencoming here for years and you just started working here last month." << std::endl;
}

void	Karen::_error(void)
{
	std::cout << "[ERROR]\n"
		<< "This is unacceptable, I want to speak to the manager now." << std::endl;
}

void	Karen::complain(std::string level)
{
	int			int_level = 4;
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (!level.compare(levels[i]))
			int_level = i;
	}
	switch (int_level)
	{
		case 0 :	(this->*_func[0])();
					std::cout << std::endl;
		case 1 :	(this->*_func[1])();
					std::cout << std::endl;
		case 2 :	(this->*_func[2])();
					std::cout << std::endl;
		case 3 :	(this->*_func[3])();
					break;
		default :	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
