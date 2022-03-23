#ifndef POINT_H
#define POINT_H

namespace lab01 {

class Point {
public:
  double x, y;

  Point(double x, double y);

  double get_x();
  double get_y();
};

double distance(const Point &p1, const Point &p2);

} // namespace lab01

#endif
