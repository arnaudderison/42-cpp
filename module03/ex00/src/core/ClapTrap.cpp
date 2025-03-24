#include "ClapTrap.hpp"
#include "Color.hpp"

ClapTrap::ClapTrap() : _name("default") , _hitPoint(10), _energyPoint(10), _damage(0) {
    std::cout << YELLOW << "[INFO] " << RESET;
    std::cout << "Default Constructor called" << std::endl;
    std::cout << "ClapTrap with " << GREEN << "default" << RESET << " name created" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name) , _hitPoint(10), _energyPoint(10), _damage(0) {
    std::cout << YELLOW << "[INFO] " << RESET;
    std::cout << "Constructor called" << std::endl;
    std::cout << "ClapTrap with " << GREEN << name << RESET << " name created" << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << YELLOW << "[INFO] " << RESET;
    std::cout << "Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : _hitPoint(other._hitPoint), _energyPoint(other._energyPoint), _damage(other._damage) {
    std::cout << YELLOW << "[INFO] " << RESET;
    std::cout << "Contructor of copy called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << YELLOW << "[INFO] " << RESET;
    std::cout << "Operaotr of assignement is called" << std::endl;
    if(this != &other) {
        this->_hitPoint = other._hitPoint;
        this->_energyPoint = other._energyPoint;
        this->_damage = other._damage;
    }
    return *this;
}

void ClapTrap::attack(const std::string& target) {
    if(this->_energyPoint <= 0) {
        std::cout << RED << "[ATTACK FAILED]" << RESET;
        std::cout << this->_name << "has no more hit energy point" << std::endl; 
        return;
    }
    if(this->_hitPoint <= 0) {
        std::cout << RED << "[ATTACK FAILED]" << RESET;
        std::cout << this->_name << "is dead" << std::endl; 
        return;
    }

    std::cout << "ClapTrap " << GREEN << this->_name << RESET;
    std::cout << " attacks " << GREEN << target << RESET;
    std::cout << ", causing " << this->_damage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoint > amount)
		this->_hitPoint -= amount;
	else if (this->_hitPoint > 0)
		this->_hitPoint = 0;
	else
	{
		std::cout << "ClapTrap " << GREEN << this->_name << RESET;
        std::cout << " is already dead." << std::endl;
		return ;
	}
    std::cout << RED << "[-] " << RESET;
	std::cout << "ClapTrap " << GREEN << this->_name << RESET;
    std::cout << " was attacked and lost " << amount << " hit points, he now has " << this->_hitPoint << " hit points." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoint > 0 && this->_hitPoint > 0 && this->_hitPoint + amount <= 10)
	{
		this->_hitPoint += amount;
        std::cout << GREEN << "[+] " << RESET;
		std::cout << "ClapTrap " << this->_name << " repaired itself and gained " << amount << " of hit points, he now has " << this->_hitPoint << " hit points." << std::endl;
		this->_energyPoint--;
	}
	else if (this->_energyPoint <= 0)
    {
		std::cout << "ClapTrap " << GREEN << this->_name << RESET;
        std::cout << " is not able to repair itself, because he doesn't have enough energy points" << std::endl;
    }
	else if (this->_hitPoint <= 0)
    {
		std::cout << "ClapTrap " << GREEN << this->_name << RESET;
        std::cout << " is not able to repair itself, because he doesn't have enough hit points." << std::endl;
    }
	else
    {
		std::cout << "ClapTrap " << GREEN << this->_name << RESET;
        std::cout << " can't be repaired to have more than 10 hit points." << std::endl;
    }
}
