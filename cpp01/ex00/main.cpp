#include "Zombie.hpp"

int	main(void)
{
	Zombie zombie_zero("Agamemnon");
	
	Zombie* zombie_one = newZombie("Hektor");
	zombie_one->announce();
	delete zombie_one;
	
	zombie_zero.announce();
	randomChump("Achilles");
	
	{
		Zombie& zombie_two = zombie_zero;
		zombie_two.announce();
	}

	zombie_zero.announce();
	return (0);
}
