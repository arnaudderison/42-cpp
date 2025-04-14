#include "Color.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
    std::cout << CYAN << "╔══════════════════════════════════╗\n";
    std::cout << "║       🛠️  TESTING CLAPTRAP        ║\n";
    std::cout << "╚══════════════════════════════════╝" << RESET << std::endl;

    {
        ClapTrap a;
        ClapTrap b("aderison");

        std::cout << BLUE << "\n→ Test A:\n" << RESET;
        a.attack("some other robot");
        a.takeDamage(10);
        a.takeDamage(10);
        a.beRepaired(5);
        a.attack("some other other robot");

        std::cout << GREEN << "\n→ Test B:\n" << RESET;
        b.beRepaired(3);
        b.beRepaired(3);

        std::cout << std::endl << std::endl;
    }

    std::cout << CYAN << "╔══════════════════════════════════╗\n";
    std::cout << "║       🛡️  TESTING SCAVTRAP        ║\n";
    std::cout << "╚══════════════════════════════════╝" << RESET << std::endl;

    {
        ScavTrap c;
        ScavTrap d("Savage");

        std::cout << BLUE << "\n→ Test C:\n" << RESET;
        c.attack("CloneTrap");
        c.beRepaired(22);
        c.takeDamage(21);
        c.beRepaired(22);
        c.guardGate();
        c.guardGate();

        std::cout << GREEN << "\n→ Test D:\n" << RESET;
        d.attack("Savage-clone");
        d.takeDamage(101);
        d.takeDamage(15);
        d.attack("ScavTrap-clone");

        std::cout << std::endl << std::endl;
    }

    std::cout << CYAN << "╔══════════════════════════════════╗\n";
    std::cout << "║       💎 TESTING DIAMONDTRAP      ║\n";
    std::cout << "╚══════════════════════════════════╝" << RESET << std::endl;

    {
        std::cout << BLUE << "\n→ Constructing...\n" << RESET;
        DiamondTrap a;
        DiamondTrap b("Giga Chadd");
        DiamondTrap c(a);

        std::cout << YELLOW << "\n→ Testing...\n" << RESET;
        a.whoAmI();
        a.attack("some super random dude");

        b.whoAmI();
        b.attack("Chadd-clone");

        c.whoAmI();

        std::cout << RED << "\n→ Deconstructing...\n" << RESET;
    }

    std::cout << std::endl;
    return 0;
}
