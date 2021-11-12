#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	{
		FragTrap ft0("M0x");
		ft0.beRepaired(1);
		ft0.takeDamage(1);
		ft0.beRepaired(1);
		ft0.takeDamage(10);
		ft0.beRepaired(10);
		ft0.attack("Porcinet");
		ft0.attack("Pumba");
		ft0.takeDamage(9);
		ft0.highFivesGuys();
		ft0.takeDamage(200);
	}
}