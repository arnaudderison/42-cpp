#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(const Point a, const Point b, const Point c, const Point point);

int main(void)
{
    const Point a(1, 1);
    const Point b(2, 3);
    const Point c(3, 1);
    const Point point(2.5f, 1.5f);

    // std::cout << "point a: " << a.getx() << " " << a.gety() << std::endl;
    // std::cout << "point b: " << b.getx() << " " << b.gety() << std::endl;
    // std::cout << "point c: " << c.getx() << " " << c.gety() << std::endl;
    // std::cout << "point: " << point.getx() << " " << point.gety() << std::endl;

    std::cout << "est dans le triangle: " << bsp(a, b, c, point) << std::endl;
	return (0);
}