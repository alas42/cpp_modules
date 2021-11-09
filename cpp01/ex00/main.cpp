#include "Zombie.hpp"

int	main(void)
{
	Zombie zombie_zero("Agamemnon");

	Zombie* zombie_one = newZombie("Hektor");
	zombie_one->announce();
	delete zombie_one;

	Zombie& zombie_two = zombie_zero;
	zombie_two.announce();

	randomChump("Achilles");
	return (0);
}
