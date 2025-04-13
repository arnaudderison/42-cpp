#include "FragTrap.hpp"
#include "Color.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	this->_hitPoint = 100;
	this->_energyPoint = 100;
	this->_damage = 30;
  std::cout << YELLOW << "[INFO] " << RESET;
	std::cout << "FragTrap Default Constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other): ClapTrap(other)
{
  std::cout << YELLOW << "[INFO] " << RESET;
	std::cout << "FragTrap Copy Constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	this->_hitPoint = 100;
	this->_energyPoint = 100;
	this->_damage = 30;
  std::cout << YELLOW << "[INFO] " << RESET;
	std::cout << "FragTrap Constructor for the name ";
  std::cout << BLUE << this->_name << RESET;
  std::cout << " called" << std::endl;
}

// Deconstructors
FragTrap::~FragTrap()
{
  std::cout << YELLOW << "[INFO] " << RESET;
	std::cout << "FragTrap Deconstructor for ";
  std::cout << BLUE << this->_name << RESET;
  std::cout << " called" << std::endl;
}

// Overloaded Operators
FragTrap &FragTrap::operator=(const FragTrap &other)
{
	std::cout << "FragTrap Assignation operator called" << std::endl;
  if(this != &other) {
    this->_name = other._name;
    this->_hitPoint = other._hitPoint;
    this->_energyPoint = other._energyPoint;
    this->_damage = other._damage;
  }
	return *this;
}

// Public Methods

void	FragTrap::highFiveGuys(void)
{
	std::cout << "FragTrap " << this->_name << ": You want a high five?\n\t*WHAMM*\nHere you go." << std::endl;
}