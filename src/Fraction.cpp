#include "Fraction.h"
#include <numeric>

using namespace lab01;

using std::domain_error;
using std::ostream;
using std::weak_ordering;

int Fraction::count = 0;

Fraction::Fraction(int numerator, int denominator)
    : numerator(numerator), denominator(denominator) {

  if (denominator == 0)
    throw domain_error("cannot divide by 0");

  nth_ = this->count++;

  int gcd = std::gcd(numerator, denominator);
  this->denominator /= gcd;
  this->numerator /= gcd;
}

Fraction::Fraction(Fraction const &other)
    : Fraction(other.numerator, other.denominator) {}

Fraction::~Fraction() {}

weak_ordering Fraction::operator<=>(const Fraction &other) const {
  if (denominator == other.denominator && numerator == other.numerator)
    return weak_ordering::equivalent;

  if (denominator == other.denominator)
    return numerator <=> other.numerator;

  auto lcm = std::lcm(denominator, other.denominator);
  auto num1 = (numerator * (lcm / denominator));
  auto num2 = (other.numerator * (lcm / other.denominator));

  return num1 <=> num2;
}

bool Fraction::operator==(const Fraction &other) const {
  return (*this <=> other) == 0;
}

ostream &lab01::operator<<(ostream &os, const Fraction &f) {
  os << f.numerator << '/' << f.denominator;
  return os;

} // namespace lab01

ostream &Fraction::out(ostream &os) const { return os << *this; }

Fraction Fraction::operator*(Fraction const &other) const {
  int num = numerator * other.numerator;
  int den = denominator * other.denominator;
  return Fraction(num, den);
}

Fraction Fraction::mul(Fraction const &other) const { return *this * other; }

Fraction Fraction::operator+(Fraction const &other) const {
  auto lcm = std::lcm(denominator, other.denominator);
  auto num1 = (numerator * (lcm / denominator));
  auto num2 = (other.numerator * (lcm / other.denominator));
  return Fraction(num1 + num2, lcm);
}
Fraction Fraction::add(Fraction const &other) const { return *this + other; }

Fraction Fraction::operator-(Fraction const &other) const {
  auto lcm = std::lcm(denominator, other.denominator);
  auto num1 = (numerator * (lcm / denominator));
  auto num2 = (other.numerator * (lcm / other.denominator));
  return Fraction(num1 - num2, lcm);
}
Fraction Fraction::sub(Fraction const &other) const { return *this - other; }

Fraction Fraction::inverse() const { return Fraction(denominator, numerator); }

Fraction Fraction::operator/(const Fraction &other) const {
  return *this * other.inverse();
}

Fraction Fraction::div(const Fraction &other) const { return *this / other; }

int Fraction::nth() const { return nth_; }
