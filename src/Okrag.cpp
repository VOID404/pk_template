#include "Okrag.h"
#include "Punkt.h"
#include <ostream>

using std::ostream;

Okrag::Okrag(float x, float y, float r) : r(r), Punkt(x, y) {}

Okrag::~Okrag() {}

ostream &operator<<(ostream &os, const Okrag &o) {
  return os << "Okrąg [Promień: " << o.r << ", Środek" << (Punkt)o << ']';
}
