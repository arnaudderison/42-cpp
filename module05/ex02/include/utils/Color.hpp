#pragma once

#include <iostream>
#include <string>

class Color {
    private:
        int _color;
    public:
        Color();
        Color(int color);
        ~Color();
        Color(const Color& other);
        Color& operator=(const Color& other);

        int getColor() const;
};

std::ostream& operator<<(std::ostream& os, const Color& c);

const Color RESET(0);
const Color RED(31);
const Color GREEN(32);
const Color YELLOW(33);
const Color BLUE(34);
const Color MAGENTA(35);
const Color CYAN(36);
const Color WHITE(37);
const Color BOLD(1);
const Color UNDERLINE(4);
