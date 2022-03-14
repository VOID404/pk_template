#include "Fraction.h"
#include <ostream>

using namespace lab01;

using std::ostream;

Fraction::Fraction(int numerator, int denominator) {}
Fraction::Fraction(Fraction const &other) {}
Fraction::~Fraction() {}

bool Fraction::operator==(const Fraction &other) const {}
ostream &lab01::operator<<(ostream &os, const Fraction &f) {}

Fraction Fraction::add(Fraction const &other) const {}
Fraction Fraction::sub(Fraction const &other) const {}
Fraction Fraction::mul(Fraction const &other) const {}
Fraction Fraction::div(const Fraction &other) const {}

Fraction Fraction::inverse() const {}

ostream &Fraction::out(ostream &os) const {}

int Fraction::nth() const {}
