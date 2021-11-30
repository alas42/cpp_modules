#include "ICharacter.hpp"


ICharacter::~ICharacter(void)
{
	std::cout << RED << "ICharacter got destroyed." << RESET << std::endl;
}

ICharacter & ICharacter::operator = (ICharacter const & other)
{
	return *this;
}
