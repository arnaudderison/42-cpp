#pragma once

#include <string>
#include <iostream>
#include <stack>
#include <sstream>

class RNP {
  public:
    RNP();
    ~RNP();
    RNP(const RNP& other);
    RNP& operator=(const RNP& other);

    std::string evaluate(std::string const& expr);

    private:
      bool isOperator(const char c) const;
      void apllyOpe(std::stack<int>& stk, const char op);
};