#include "ScavTrap.hpp"
#include "Color.hpp"

ScavTrap::ScavTrap(): ClapTrap("default", 100, 50, 20), _guardingGate(false)
{
    std::cout << YELLOW << "[INFO] " << RESET;
    std::cout << "Default Constructor called" << std::endl;
    std::cout << "ScavTrap with " << GREEN << "default" << RESET << " name created" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name, 100, 50, 20), _guardingGate(false)
{
    std::cout << YELLOW << "[INFO] " << RESET;
    std::cout << "Constructor called" << std::endl;
    std::cout << "ScavTrap with " << GREEN << this->_name << RESET << " name created" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) 
{
    this->_guardingGate = other._guardingGate;
    std::cout << "ScavTrap Copy Constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    std::cout << "ScavTrap Assignation operator called" << std::endl;
    if(this != &other)
    {
        this->_name = other._name;
        this->_hitPoint = other._hitPoint;
        this->_energyPoint = other._energyPoint;
        this->_damage = other._damage;
        this->_guardingGate = other._guardingGate;
    }
    return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor for " << this->_name << " called" << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (_energyPoint > 0 && _hitPoint > 0)
	{
		std::cout << "ScavTrap " << GREEN << _name << RESET;
        std::cout << " attacks " << target << ", causing " << _damage << " points of damage!" << std::endl;
		_energyPoint--;
	}
	else if (_energyPoint == 0)
    {
		std::cout << "ScavTrap " << GREEN << _name << RESET;
        std::cout << " is not able to attack " << target << ", because he has no energy points left." << std::endl;
    }
	else
    {

		std::cout << "ScavTrap "<< GREEN << _name << RESET;
        std::cout << " is not able to attack " << target << ", because he has not enough hit points." << std::endl;
    }
}

void	ScavTrap::guardGate(void)
{
	if (!_guardingGate)
	{
		_guardingGate = true;
		std::cout << "ScavTrap " << _name << " is now guarding the gate." << std::endl;
	}
	else
    {
		std::cout << "ScavTrap " << GREEN << _name << RESET;
        std::cout << " is already guarding the gate." << std::endl;
    }
}