#include "Zombie.hpp"
#include <cstdlib>

int	main(void)
{
	int			n;
	std::string entry;

	n = 0;
	while (n <= 0)
	{
		std::cout << "Enter a valid number N of zombies (N > 0):" << std::endl;
		std::getline(std::cin, entry);
		if(std::cin.eof())
				std::cin.clear();
		n = atoi(entry.c_str());
		if (n <= 0)
			std::cout << "\nAren't you a bright one ?" << std::endl;
		std::cout << "\nCall of method zombieHorde():" << std::endl;

		Zombie* zombies = zombieHorde(n, "Bond");
		for (int i = 0; i < n; i++)
		{
			zombies[i].announce();
		}
		std::cout << "\nDeletion of the horde:" << std::endl;
		delete [] zombies;
		std::cout << std::endl;
	}
	return (0);
}
