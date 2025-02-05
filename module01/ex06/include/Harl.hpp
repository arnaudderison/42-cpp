#include <iostream>
#include <string>

#pragma once

class Harl {
  public:
    Harl();
    ~Harl();

    void complain(std::string level);

  private:
    void debug();
    void info();
    void warning();
    void error();
};
