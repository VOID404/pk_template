#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

namespace lab01 {

class Fraction {
  int numerator, denominator;

public:
  // Those are required for tests
  bool operator==(Fraction const &other) const;
  friend std::ostream &operator<<(std::ostream &os, const Fraction &f);

  int nth() const;

  Fraction mul(Fraction const &other) const;
  Fraction div(Fraction const &other) const;
  Fraction add(Fraction const &other) const;
  Fraction sub(Fraction const &other) const;
  Fraction inverse() const;

  std::ostream &out(std::ostream &os) const;

  Fraction(int numerator = 1, int denominator = 1);
  Fraction(Fraction const &other);
  virtual ~Fraction();
};

} // namespace lab01

#endif /* FRACTION_H */
