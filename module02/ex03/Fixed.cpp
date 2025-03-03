#include "Fixed.hpp"

const int Fixed::_nb_bits = 8;

// constructeurs
Fixed::Fixed(): _fix_value(0) {
  // std::cout << "Default constructeur called" << std::endl; 
}

Fixed::Fixed(const int nb)
{
  // std::cout << "Int Constructor called" << std::endl;
  this->_fix_value = nb << this->_nb_bits;
}

Fixed::Fixed(const float input)
{
	// std::cout << "Float Constructor called" << std::endl;
	this->_fix_value = roundf(input * (1 << this->_nb_bits));
}

Fixed::~Fixed() {
  // std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy) {
  // std::cout << "Copy constructor called" << std::endl;

  *this = copy;
}

// operators
Fixed &Fixed::operator=(const Fixed& src) {
  // std::cout << "copy assignement operator called" << std::endl;

  if(this != &src)
        this->_fix_value = src.getRawBits();

  return *this;
}

bool Fixed::operator>(const Fixed& src) const {
  return (this->toFloat() > src.toFloat());
}

bool Fixed::operator<(const Fixed& src) const {
  return (this->toFloat() < src.toFloat());
}

bool Fixed::operator>=(const Fixed& src) const {
  return (this->toFloat() >= src.toFloat());
}

bool Fixed::operator<=(const Fixed& src) const{
  return (this->toFloat() <= src.toFloat());
}

bool Fixed::operator==(const Fixed& src) const {
  return (this->toFloat() == src.toFloat());
}

bool Fixed::operator!=(const Fixed& src) const {
  return (this->toFloat() != src.toFloat());
}

Fixed Fixed::operator+(const Fixed& src) const {
  Fixed result;

  result = Fixed(this->toFloat() + src.toFloat());
  return (result);
}

Fixed Fixed::operator-(const Fixed& src) const {
  Fixed result;

  result = Fixed(this->toFloat() - src.toFloat());
  return (result);
}

Fixed Fixed::operator*(const Fixed& src) const {
  Fixed result;
  
  result = Fixed(this->toFloat() * src.toFloat());
  return (result);
}

Fixed Fixed::operator/(const Fixed& src) const {
  Fixed result;

  if(src.toFloat() == 0)
    return (Fixed(0));
  result = Fixed(this->toFloat() / src.toFloat());
  return (result);
}

Fixed& Fixed::operator++(){
  setRawBits(this->getRawBits() + 1);
  return *this;
}

Fixed& Fixed::operator--() {
  setRawBits(this->getRawBits() - 1);
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed tmp;

  tmp = *this;
  this->setRawBits(this->getRawBits() + 1);
  return tmp;
}

Fixed Fixed::operator--(int) {
  Fixed tmp;

  tmp = *this;
  this->setRawBits(this->getRawBits() - 1);
  return tmp;
}

// fonctions
float	Fixed::toFloat(void) const
{
	return ((float)this->_fix_value / (float)(1 << this->_nb_bits));
}

int	Fixed::toInt(void) const
{
	return (this->_fix_value >> this->_nb_bits);
}

int Fixed::getRawBits(void) const {
  // std::cout << "getRawBits member fonction called" << std::endl;

  return _fix_value;
}

void Fixed::setRawBits(const int raw) {
  // std::cout << "setRawBits member fonction called" << std::endl;

  this->_fix_value = raw;
}

const Fixed	&Fixed::min(Fixed const &copy1, Fixed const &copy2)
{
	if (copy1 < copy2)
		return (copy1);
	return (copy2);
}

const Fixed	&Fixed::max(Fixed const &copy1, Fixed const &copy2)
{
	if (copy1 > copy2)
		return (copy1);
	return (copy2);
}

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return (o);
}
