#ifndef PUNKT_H
#define PUNKT_H

#include <iostream>

class Punkt {
private:
  float x;
  float y;

public:
  Punkt(float x, float y);
  ~Punkt();

  friend std::ostream &operator<<(std::ostream &os, const Punkt &f);
};

#endif /* PUNKT_H */
