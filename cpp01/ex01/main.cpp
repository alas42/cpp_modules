#include "Zombie.hpp"

int	main(void)
{
	int	n;

	n = 11;
	Zombie* zombies = zombieHorde(n, "Bond");
	for (int i = 0; i < n; i++)
	{
		zombies[i].announce();
	}
	delete [] zombies;
	return (0);
}
