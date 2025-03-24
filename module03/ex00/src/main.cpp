#include "Color.hpp"
#include "ClapTrap.hpp"
#include <iostream>

int main()
{
    ClapTrap player("aderison");

    player.attack("Arnaud");
    player.takeDamage(3);
    player.takeDamage(3);
    player.beRepaired(6);
    player.takeDamage(10);
    player.beRepaired(15);
    return 0;
}