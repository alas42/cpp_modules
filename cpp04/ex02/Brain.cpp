#include "Brain.hpp"

/*
** Canonical Form
*/
Brain::Brain(void)
{
	std::string names[8] = {"Alexandre", "Benjamin", "Charlotte", "Delphine", "Etienne", "Franck", "Gabrielle", "Helene"};
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = names[i % 8];
	}
	std::cout << GREEN << "A brain got created." << RESET << std::endl;
}

Brain::Brain(Brain const & other)
{
	*this = other;
	std::cout << GREEN << "A brain got created thank another." << RESET << std::endl;
}

Brain::~Brain(void)
{
	std::cout << RED << "A brain got destroyed." << RESET << std::endl; 
}

Brain & Brain::operator = (Brain const & other)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
	return *this;
}
/*
** End of Canonical Form
*/

/*
** Other Constructors
*/
/*
** End of Other Constructors
*/

/*
** Misc
*/
/*
** End of Misc
*/

/*
** Guetters and Setters
*/
std::string const & Brain::getIdeaX(int const x) const
{
	if (x >= 0 && x <= 99)
		return this->ideas[x];
	std::cout << MAGENTA << "Brain::getIdeaX(" << x << ") is out of bounds, should be between [0 - 99]\n"
		<< "Returning ideas[0]." << RESET << std::endl;
	return this->ideas[0];
}

void Brain::setIdeaX(int const x, std::string const & str)
{
	if (x >= 0 && x <= 99)
	{
		this->ideas[x] = str;
		return ;
	}
	std::cout << MAGENTA << "Brain::setIdeaX(" << x << ", ...) is out of bounds, should be between [0 - 99]\n"
		<< "Setting ideas[0]." << RESET << std::endl;
	this->ideas[0] = str;
}
/*
** End of Guetters and Setters
*/
