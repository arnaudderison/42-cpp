#pragma once

#include <string>
#include <iostream>

class RNP {
  public:
    RNP();
    ~RNP();
    RNP(const RNP& other);
    RNP& operator=(const RNP& other);

    std::string evaluate(std::string const& expr);

    private:
      bool isOperator(const char c) const;

};