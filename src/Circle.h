#ifndef CIRCLE_H
#define CIRCLE_H

#include "Point.h"
#include <ostream>

namespace lab01 {

using std::ostream;

enum CircleRelations {
  ROZLACZNE_ZEWNETRZNIE,
  STYCZNE_ZEWNETRZNIE,
  PRZECINAJACE,
  STYCZNE_WEWNETRZNIE,
  ROZLACZNE_WEWNETRZNIE,
  WSPOLSRODKOWE
};

class Circle : Point {
private:
  double r;

public:
  Circle(double x, double y, double r);
  inline Circle(const Circle &c);

  const double get_r();
  const double area();
  const double perimeter();
  ostream &print(ostream &os);
  CircleRelations circlesLocation(const Circle &other);
};

} // namespace lab01
#endif
