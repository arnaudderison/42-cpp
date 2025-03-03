#include "Point.hpp"

static float barycentre( Point const a, Point const b, Point const c)
{
    return (a.getx() - c.getx()) * (b.gety() - c.gety()) - (b.getx() - c.getx()) * (a.gety() - c.gety());
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
  bool b1, b2, b3;

  b1 = barycentre(point, a, b) < 0.0f;
  b2 = barycentre(point, b, c) < 0.0f;
  b3 = barycentre(point, c, a) < 0.0f;
  
  return ((b1 == b2) && (b2 == b3));
}