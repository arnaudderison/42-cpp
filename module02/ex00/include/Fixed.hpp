#pragma once

#include <iostream>
#include <string>

class Fixed {
  private:
    int _fix_value;
    static const int _nb_bits;
     
  public:
   Fixed();
   ~Fixed();
   Fixed(const Fixed& copy);
   Fixed &operator=(const Fixed& src);

   int getRawBits(void) const;
   void setRawBits(const int raw);
};

