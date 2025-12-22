#include "RNP.hpp"

RNP::RNP() {}
RNP::~RNP() {}
RNP::RNP(const RNP& other) {
    (void)other;
}
RNP& RNP::operator=(const RNP& other) {
    if (this != &other) {
        (void)other;
    }
    return *this;
}

std::string RNP::evaluate(std::string const& expr) {
    std::cout << "Evaluating expression: " << expr << std::endl;

    for(size_t i = 0; i < expr.size(); i++) {
      if(std::isspace(expr[i])) continue;
      if(std::isdigit(expr[i])) std::cout << "Je push: " << expr[i] - '0' << std::endl;
      else if (isOperator(expr[i])) std::cout << "C'est un operateur: " << expr[i] << std::endl;
      else throw std::runtime_error("Error: invalid character in expression.");
    }
    return "";
}

bool RNP::isOperator(const char c) const {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}