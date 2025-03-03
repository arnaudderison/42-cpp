#pragma once

#include <iostream>
#include <string>
#include <cmath>

class Fixed {
  private:
    int _fix_value;
    static const int _nb_bits;
     
  public:
  //contructeurs
   Fixed();
   Fixed(const int nb);
   Fixed(const float);
   ~Fixed();
   Fixed(const Fixed& copy);

   //operators
   Fixed &operator=(const Fixed& src);
   bool operator>(const Fixed& src) const;
   bool operator<(const Fixed& src) const;
   bool operator>=(const Fixed& src) const;
   bool operator<=(const Fixed& src) const;
   bool operator==(const Fixed& src) const;
   bool operator!=(const Fixed& src) const;
   Fixed operator+(const Fixed& src) const;
   Fixed operator-(const Fixed& src) const;
   Fixed operator*(const Fixed& src) const;
   Fixed operator/(const Fixed& src) const;
   Fixed& operator++();
   Fixed& operator--();
   Fixed operator++(int);
   Fixed operator--(int);
   //fonctions
   float toFloat(void) const;
   int toInt(void) const;
   int getRawBits(void) const;
   void setRawBits(const int raw);
   static const Fixed	&min(Fixed const &copy1, Fixed const &copy2);
   static const Fixed	&max(Fixed const &copy1, Fixed const &copy2);
};

std::ostream    &operator<<(std::ostream &o, Fixed const &fixed);