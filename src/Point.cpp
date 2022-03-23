#include "Point.h"
#include <cmath>
#include <iterator>
#include <math.h>

using namespace lab01;

Point::Point(double x, double y) : x(x), y(y) {}
double Point::get_x() { return x; }
double Point::get_y() { return y; }

double distance(const Point &p1, const Point &p2) {
  return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}
