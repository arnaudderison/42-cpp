#include "DiamondTrap.hpp"

// Constructors
DiamondTrap::DiamondTrap(): ClapTrap("defaultDT_clap_trap")
{
	this->_name = "defaultDT";
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

// Deconstructors
DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Deconstructor for " << this->_name << " called" << std::endl;
}

// Overloaded Operators
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &src)
{
	std::cout << "DiamondTrap Assignation operator called" << std::endl;
	this->_name = src._name + "_clap_trap";
	this->_hitPoint = src._hitPoint;
	this->_energyPoint = src._energyPoint;
	this->_damage = src._damage;
	return *this;
}

// Public Methods
void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "Hello i am a DiamondTrap named " << this->_name <<
	" and i am originated from the ClapTrap named " << ClapTrap::_name << "." <<
	std::endl;
}