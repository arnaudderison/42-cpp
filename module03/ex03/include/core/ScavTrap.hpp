#pragma once
#include "ClapTrap.hpp"
#include <string>


class ScavTrap : virtual public ClapTrap {
    private:
        bool _guardingGate;
    public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap& other);
        ScavTrap& operator=(const ScavTrap& other);
        virtual ~ScavTrap();

        void attack(const std::string& target);
        void guardGate(void);
};