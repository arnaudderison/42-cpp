#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
  std::cout << name << " is dead" << std::endl; 
}

void Zombie::announce() {
  std::cout << name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) {
  this->name = name;
}
