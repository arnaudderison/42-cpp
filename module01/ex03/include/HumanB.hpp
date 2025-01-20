#include "Weapon.hpp"

#pragma once

class HumanB {
  private:
    std::string _name;
    Weapon* _weapon;
  public:
    HumanB(std::string);
    ~HumanB();
    void setWeapon(Weapon& weapon);
    void attack();
};

