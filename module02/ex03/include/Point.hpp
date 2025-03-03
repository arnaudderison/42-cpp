#pragma once

#include "Fixed.hpp"

class Point {
  private:
    Fixed const _x;
    Fixed const _y;
  public:
    Point();
    Point(const float x, const float y);
    Point(const Point& copy);
    ~Point();
    Point &operator=(const Point& src);
    float getx(void) const;
    float gety(void) const;

};