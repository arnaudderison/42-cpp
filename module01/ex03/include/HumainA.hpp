#include "Weapon.hpp"

#pragma once

class HumanA {
  private:
    std::string name;
    Weapon& weapon;

  public:
    HumanA(std::string name, Weapon& weapon);
    ~HumanA(void);
}
