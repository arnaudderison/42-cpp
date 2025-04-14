#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap("default_D_clap_trap")
{
	this->_name = "default diamond";
	this->_hitPoint = FragTrap::_hitPoint;
	this->_energyPoint = ScavTrap::_energyPoint;
	this->_damage = FragTrap::_damage;
	std::cout << "DiamondTrap Default Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy): ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
	*this = copy;
	std::cout << "DiamondTrap Copy Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_trap")
{
	this->_name = name;
	this->_hitPoint = FragTrap::_hitPoint;
	this->_energyPoint = ScavTrap::_energyPoint;
	this->_damage = FragTrap::_damage;
	std::cout << "DiamondTrap Constructor for the name " << this->_name << " called" << std::endl;
}


DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Deconstructor for " << this->_name << " called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	if(this != &other)
	{
		std::cout << "DiamondTrap Assignation operator called" << std::endl;
		this->_name = other._name + "_clap_trap";
		this->_hitPoint = other._hitPoint;
		this->_energyPoint = other._energyPoint;
		this->_damage = other._damage;
	}
	return *this;
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "Hello i am a DiamondTrap named " << this->_name <<
	" from the ClapTrap named " << ClapTrap::_name <<
	std::endl;
}