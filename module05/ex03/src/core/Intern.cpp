#include "Intern.hpp"

Intern::Intern() {}
Intern::~Intern() {}
Intern::Intern(const Intern& other) : 
    _name(other._name),
    _target(other._target) {}

Intern& Intern::operator=(const Intern& other) {
    if(this != &other) {
        this->_name = other._name;
        this->_target = other._target;
    }
    return *this;
}

Intern::Intern(const std::string name, const std::string target) : 
    _name(name),
    _target(target) {}
