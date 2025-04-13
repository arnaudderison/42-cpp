#pragma once

#include <iostream>
#include <string>

class ClapTrap {
    protected:
        std::string _name;
        unsigned int _hitPoint;
        unsigned int _energyPoint;
        unsigned int _damage;
    public:
        // constructor
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(std::string name, unsigned int hitPoint, unsigned int energyPoint, unsigned int damage);
        virtual ~ClapTrap();
        ClapTrap(const ClapTrap& other);

        //operator
        ClapTrap &operator=(const ClapTrap& src);

        //function
        virtual void attack(const std::string& target);
        void takeDamage(unsigned int amout);
        void beRepaired(unsigned int amount);
};