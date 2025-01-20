#include "Fixed.hpp"

const int Fixed::_nb_bits = 8;

Fixed::Fixed(): _fix_value(0) {
  std::cout << "Default constructeur called" << std::endl; 
}

Fixed::~Fixed() {
  std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy) {
  std::cout << "Copy constructor called" << std::endl;

  *this = copy;
}

Fixed &Fixed::operator=(const Fixed& src) {
  std::cout << "copy assignement operator called" << std::endl;

  if(this != &src)
        this->_fix_value = src.getRawBits();

  return *this;
}

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member fonction called" << std::endl;

  return _fix_value;
}

void Fixed::setRawBits(const int raw) {
  std::cout << "setRawBits member fonction called" << std::endl;

  this->_fix_value = raw;
}
