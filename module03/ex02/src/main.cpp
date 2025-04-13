#include "Color.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main()
{
    std::cout << CYAN << "### TESTING CLAPTRAP ###\n" << RESET << std::endl;
	{
		ClapTrap a;
		ClapTrap b("aderison");

		a.attack("some other robot");
		a.takeDamage(10);
		a.takeDamage(10);
		a.beRepaired(5);
		a.attack("some other other robot");

		b.beRepaired(3);
		b.beRepaired(3);
		std::cout << std::endl << std::endl;
	}

	std::cout << "\n\n### TESTING SCAVTRAP ###\n" << std::endl;
	{
		ScavTrap c;
		ScavTrap d("Savage");

		c.attack("CloneTrap");
		c.beRepaired(22);
		c.takeDamage(21);
		c.beRepaired(22);
		c.guardGate();
		c.guardGate();

		d.attack("Savage-clone");
		d.takeDamage(101);
		d.takeDamage(15);
		d.attack("ScavTrap-clone");
        std::cout << std::endl << std::endl;
	}
    return 0;
}