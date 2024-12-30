#include "HumanB.hpp"


HumanB::HumanB(std::string name): _name(name) {
  std::cout << "HumanB " << name << "created" << std::endl;
}

HumanB::~HumanB() {
  std::cout << "HumanB " << this->_name << "is deads" << std::endl;
}

void HumanB::attack() {
  std::cout << this->_name << "attacks with his ";
  std::cout << this->_weapon->getType() << std::endl; 
}

void HumanB::setWeapon(Weapon& weapon) {
  this->_weapon = &weapon;
}
