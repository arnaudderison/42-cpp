#pragma once 
#include <string>
#include <iostream>

class Weapon {
  private:
    std::string _type;

  public:
    Weapon(std::string type);
    ~Weapon();
    const std::string& getType();
    void setType(std::string type);
};

