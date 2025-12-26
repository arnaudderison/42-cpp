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
    std::stack<int> stk;
    std::ostringstream oss;

    for(size_t i = 0; i < expr.size(); i++) {
      if(std::isspace(expr[i])) continue;
      if(std::isdigit(expr[i])) stk.push(expr[i] - '0');
      else if (isOperator(expr[i])) apllyOpe(stk, expr[i]);
      else throw std::runtime_error("Error: invalid character in expression.");
    }
    if (stk.size() != 1) {
        throw std::runtime_error("Error: the user input has too many values.");
    }
    oss << stk.top();
    return oss.str();
}

bool RNP::isOperator(const char c) const {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

void RNP::apllyOpe(std::stack<int>& stk, const char op) {
    if (stk.size() < 2) {
        throw std::runtime_error("Error: insufficient values in expression.");
    }

    int b = stk.top(); stk.pop();
    int a = stk.top(); stk.pop();
    int result;

    switch (op) {
        case '+': result = a + b; break;
        case '-': result = a - b; break;
        case '*': result = a * b; break;
        case '/':
            if (b == 0) {
                throw std::runtime_error("Error: division by zero.");
            }
            result = a / b; break;
        default:
            throw std::runtime_error("Error: unknown operator.");
    }
    stk.push(result);
}
