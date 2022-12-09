#include "Punkt.h"
#include <ostream>

using std::ostream;

Punkt::Punkt(float x, float y) : x(x), y(y) {}

Punkt::~Punkt() {}

ostream &operator<<(ostream &os, const Punkt &p) {
  return os << '(' << p.x << ',' << p.y << ')';
}
