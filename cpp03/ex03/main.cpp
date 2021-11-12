#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	{
		ClapTrap cp0("Alexandre");
		cp0.beRepaired(1);
		cp0.takeDamage(1);
		cp0.beRepaired(1);
		cp0.takeDamage(10);
		cp0.beRepaired(10);
	}
	{
		std::cout << std::endl;
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
	{
		std::cout << std::endl;
		FragTrap ft0("M0x");
		ft0.highFivesGuys();
	}
}