#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	{
		ScavTrap st0("Alexandre");
		st0.beRepaired(1);
		st0.takeDamage(1);
		st0.beRepaired(1);
		st0.takeDamage(10);
		st0.beRepaired(10);
		st0.guardGate();
		st0.attack("Porcinet");
		st0.attack("Pumba");
		st0.takeDamage(9);
		st0.beRepaired(15);
	}
}