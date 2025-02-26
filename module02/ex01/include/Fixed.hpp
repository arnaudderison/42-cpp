#pragma once

#include <iostream>
#include <string>
#include <cmath>

class Fixed {
  private:
    int _fix_value;
    static const int _nb_bits;
     
  public:
   Fixed();
   Fixed(const int nb);
   Fixed(const float);
   ~Fixed();
   Fixed(const Fixed& copy);
   Fixed &operator=(const Fixed& src);
   
   float toFloat(void) const;
   int toInt(void) const;
   int getRawBits(void) const;
   void setRawBits(const int raw);
};

std::ostream    &operator<<(std::ostream &o, Fixed const &fixed);