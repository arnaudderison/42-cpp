#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon): _name(name), _weapon(weapon) {
  std::cout << "HumanA " << name << "created with ";
  std::cout << weapon.getType() << std::endl;
}

HumanA::~HumanA() {
  std::cout << "HumanA " << this->_name << "is deads" << std::endl;
}

void HumanA::attack() {
  std::cout << this->_name << "attacks with his ";
  std::cout << this->_weapon.getType() << std::endl; 
}

void HumanA::setWeapon(Weapon& weapon) {
  this->_weapon = weapon;
}
