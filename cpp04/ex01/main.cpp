#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main(){
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		j->makeSound();
		i->makeSound();
		
		delete j;//should not create a leak
		delete i;
		std::cout << std::endl;
	}
	{
		const Animal* tab[20];

		for (int i = 0; i < 10; i++)
			tab[i] = new Dog();
		for (int i = 10; i < 20; i++)
			tab[i] = new Cat();
		for (int i = 0; i < 20; i++)
			tab[i]->makeSound();
		for (int i = 0; i < 20; i++)
			delete tab[i];
		std::cout << std::endl;
	}
	{
		std::cout << MAGENTA << "PROOF WE ARE SPEAKING ABOUT A DEEP COPY" << RESET << std::endl;
		Dog* dogA = new Dog();
		Dog* dogB = new Dog(*dogA);

		std::cout << "Idea[0] of Dog A = " << dogA->getBrain()->getIdeaX(0) << std::endl;
		std::cout << "Idea[0] of Dog B = " << dogB->getBrain()->getIdeaX(0) << std::endl;
		std::cout << "Adress of Idea[0] of Dog A = " << &dogA->getBrain()->getIdeaX(0) << std::endl;
		std::cout << "Adress of Idea[0] of Dog B = " << &dogB->getBrain()->getIdeaX(0) << std::endl;
		std::cout << "Setting Idea[0] of Dog A to 'Anonyme'" << std::endl;
		dogA->getBrain()->setIdeaX(0, "Anonyme");
		std::cout << "Idea[0] of Dog A = " << dogA->getBrain()->getIdeaX(0) << std::endl;
		std::cout << "Idea[0] of Dog B = " << dogB->getBrain()->getIdeaX(0) << std::endl;
		delete dogA;
		delete dogB;
	}
	return 0;
}