#include "Color.hpp"

Color::Color() : _color(0) {}
Color::Color(int color) : _color(color) {};
Color::~Color() {};

Color::Color(const Color& other) : _color(other._color) {};
Color& Color::operator=(const Color& other) {
    if(this != &other)
        this->_color = other._color;
    return *this;
}

int Color::getColor() const{
  return this->_color;
}

std::ostream& operator<<(std::ostream& os, const Color& c) {
    os << "\033[" << c.getColor() << "m";
    return os;
}
