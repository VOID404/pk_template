#ifndef OKRAG_H
#define OKRAG_H

#include "Punkt.h"
#include <iostream>

class Okrag : public Punkt {
private:
  float r;

public:
  Okrag(float x, float y, float r);
  ~Okrag();

  friend std::ostream &operator<<(std::ostream &os, const Okrag &o);
};

#endif /* OKRAG_H */
