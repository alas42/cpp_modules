#include "MateriaSource.hpp"

/*
** Canonical Form
*/
MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		this->_materia_templates[i] = 0;
	std::cout << GREEN << "MateriaSource got created." << RESET << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const & other)
{
	*this = other;
	std::cout << GREEN << "MateriaSource got created thank another." << RESET << std::endl;
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		delete this->_materia_templates[i];
	std::cout << RED << "MateriaSource got destroyed." << RESET << std::endl;
}

MateriaSource & MateriaSource::operator = (MateriaSource const & other)
{
	if (this == &other)
		return *this;
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia_templates[i] != 0)
			delete this->_materia_templates[i];
		if (other._materia_templates[i] == 0)
			this->_materia_templates[i] = 0;
		else
			this->_materia_templates[i] = other._materia_templates[i]->clone();
	}
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
void MateriaSource::learnMateria(AMateria * newMateria)
{
	int i = 0;

	while (i < 4)
	{
		if (this->_materia_templates[i] == 0)
		{
			this->_materia_templates[i] = newMateria;
			return ;
		}
		i++;
	}
}

AMateria * MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
		if (_materia_templates[i] != 0 && type.compare(_materia_templates[i]->getType()) == 0)
			return _materia_templates[i]->clone();
	return (0);
}
/*
** End of Misc
*/

/*
** Guetters and Setters
*/

/*
** End of Guetters and Setters
*/
