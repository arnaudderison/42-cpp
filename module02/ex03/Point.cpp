#include "Point.hpp"

Point::Point(): _x(0), _y(0) {
  // std::cout << "Default Point constructor called" << std::endl;
}

Point::Point(const float x, const float y): _x(x), _y(y) {
  // std::cout << "Point constructor called" << std::endl;
}

Point::Point(const Point& copy): _x(copy._x), _y(copy._y) {
  //  std::cout << "Copy constructor called" << std::endl;
  // *this = copy;
}

Point &Point::operator=(const Point& src) {
  //  std::cout << "copy assignement operator called" << std::endl;

   if (this == &src)
		return *this;

	return *this;
}

float Point::getx(void) const {
  return this->_x.toFloat();
}

float Point::gety(void) const {
  return this->_y.toFloat();
}

Point::~Point() {
  // std::cout << "Point destructor called" << std::endl;
}