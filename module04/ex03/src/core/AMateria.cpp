#include "AMateria.hpp"

//contrutor
AMateria::AMateria() {
  std::cout << "Default constructor";
}

AMateria::AMateria(const AMateria& other) {
  std::cout << "constructor Copy Called in AMateria" << std::endl;
  this->_type = other._type;
}

// overload
AMateria &AMateria::operator=(const AMateria& other) {
  std::cout << "Operator assignement called in AMateria" << std::endl;
  if(this != &other)
  {
    this->_type = other._type;
  }
  return *this;
}

//methodes
AMateria::AMateria(std::string const& type): _type(type) {
  std::cout << "Materia created with " << this->_type << "type." << std::endl;
}

const std::string& AMateria::getType(void) const {
  return (this->_type);
}

//Destructor
AMateria::~AMateria() {
  std::cout << "Default Destructor" << std::endl;
}
