#include "ClapTrap.hpp"

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
		ClapTrap cp1("Ama");
		cp1.attack("Porcinet");
		cp1.attack("Pumba");
		cp1.takeDamage(9);
		cp1.beRepaired(15);
	}
}