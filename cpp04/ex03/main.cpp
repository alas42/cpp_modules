#include "IMateriaSource.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "Fire.hpp"

int main()
{
	/*
	** if we don't keep the Materias used in check -> it will have leaks
	** Because unequip doesn't delete the materias (per the subject)
	** USE DOES NOT DELETE -> oldMateria does not mean usedMateria
	** IT's clearly speaking from the constructors per copy in the subject
	*/
	IMateriaSource* src = new MateriaSource(); // Basically a Factory
	src->learnMateria(new Ice()); // Learning the Template, access to clone function
	src->learnMateria(new Cure());// Same
	ICharacter* me = new Character("me");
	AMateria* tmp[10]; // Keeping every created Materias in check
	
	for (int i = 0; i < 5; i++)
		tmp[i] = src->createMateria("ice");
	for (int i = 5; i < 10; i++)
		tmp[i] = src->createMateria("cure");
	
	me->equip(tmp[0]);
	me->equip(tmp[1]);
	me->equip(tmp[2]);
	me->equip(tmp[6]);
	me->equip(tmp[9]); // does nothing (can only equip 4)

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);
	me->use(0, *bob); // does nothing because use->unequip
	me->use(8, *bob); // does nothing
	me->use(3, *bob); // will cure and not shoot ice
	me->use(2, *bob); // will shoot ice again
	std::cout << std::endl;

	bob->equip(tmp[4]);
	bob->equip(tmp[5]);
	bob->equip(tmp[7]);
	bob->equip(tmp[8]);

	bob->use(3, *bob);
	bob->use(2, *me);
	bob->use(0, *me);
	bob->use(1, *bob);

	delete bob;
	delete me;
	delete src;
	for (int i = 0; i < 10; i++)
		delete tmp[i];

	{ // UTILISATION OF MATERIA FIRE
		std::cout << "\n" << std::endl;
		IMateriaSource* src = new MateriaSource(); // Basically a Factory
		src->learnMateria(new Fire()); // Learning the Template, access to clone function
		ICharacter* balrog = new Character("Balrog");
		ICharacter* gandalf = new Character("gandalf");
		AMateria* tmp = src->createMateria("fire");
		balrog->equip(tmp);
		balrog->use(0, *gandalf);

		delete gandalf;
		delete balrog;
		delete src;
		delete tmp;
	}
	return 0;
}