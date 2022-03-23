#ifndef FRACTION_H
#define FRACTION_H

#include <compare>
#include <iostream>
#include <stdexcept>

namespace lab01 {

class Fraction {
  static int count;
  int nth_;

  int numerator, denominator;

  Fraction operator*(Fraction const &other) const;
  Fraction operator/(Fraction const &other) const;
  Fraction operator+(Fraction const &other) const;
  Fraction operator-(Fraction const &other) const;

public:
  int nth() const;

  Fraction mul(Fraction const &other) const;
  Fraction div(Fraction const &other) const;
  Fraction add(Fraction const &other) const;
  Fraction sub(Fraction const &other) const;
  Fraction inverse() const;

  std::weak_ordering operator<=>(Fraction const &other) const;
  bool operator==(Fraction const &other) const;

  friend std::ostream &operator<<(std::ostream &os, const Fraction &f);
  std::ostream &out(std::ostream &os) const;

  Fraction(int numerator = 1, int denominator = 1);
  Fraction(Fraction const &other);
  virtual ~Fraction();
};

} // namespace lab01

#endif
