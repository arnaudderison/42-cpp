#pragma once

#include <iostream>
#include <string>

class Zombie 
{
  private:
    std::string name;

  public:
    Zombie();
    ~Zombie();

    void announce(void);
    void setName(std::string name);

};

