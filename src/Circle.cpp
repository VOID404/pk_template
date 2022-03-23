#include "Circle.h"
#include "Point.h"
#include <cmath>

using namespace lab01;

using std::abs;
using std::pow;

Circle::Circle(double x, double y, double r) : Point(x, y), r(r) {}
Circle::Circle(const Circle &c) : Point(c.x, c.y), r(c.r) {}

const double Circle::get_r() { return r; }

const double Circle::area() { return M_PI * pow(r, 2); }
const double Circle::perimeter() { return M_PI * r * 2; }
ostream &Circle::print(ostream &os) {
  return os << "x: " << x << " y: " << y << " r: " << r;
}

CircleRelations Circle::circlesLocation(const Circle &other) {
  if (x == other.x && y == other.y)
    return CircleRelations::WSPOLSRODKOWE;

  auto dist = distance(*this, other);
  if (dist == r + other.r)
    return CircleRelations::STYCZNE_ZEWNETRZNIE;
  if (dist > r + other.r)
    return CircleRelations::ROZLACZNE_ZEWNETRZNIE;
  if (dist == abs(r - other.r))
    return CircleRelations::STYCZNE_WEWNETRZNIE;
  if (dist < abs(r - other.r))
    return CircleRelations::PRZECINAJACE;

  return CircleRelations::PRZECINAJACE;
}
