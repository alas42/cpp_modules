#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	{
		DiamondTrap dt0("DIAMANT");
		dt0.guardGate();
		dt0.highFivesGuys();
		dt0.whoAmI();
		dt0.attack("ONYX");
		dt0.takeDamage(50);
		dt0.beRepaired(50);
	}

}