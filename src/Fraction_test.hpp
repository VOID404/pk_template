#ifndef FRACTION_TEST_H
#define FRACTION_TEST_H

#include "Fraction.h"
#include "ut.hpp"
#include <iostream>
#include <sstream>

using std::ostringstream;
using std::string;

void test_fractions() {
  using namespace boost::ut;
  using namespace boost::ut::spec;

  describe("Fraction") = [] {
    using lab01::Fraction;

    it("counts instances") = [] {
      expect(that % Fraction().nth() == 0);
      expect(that % Fraction().nth() == 1);
      expect(that % Fraction().nth() == 2);
      expect(that % Fraction().nth() == 3);
      expect(that % (Fraction(1, 3).add(Fraction(1, 2))).nth() == 6);
    };

    it("simplifies") = [] {
      expect(that % Fraction(12, 24) == Fraction(1, 2));
    };

    it("has a default constructor") = [] {
      expect(that % Fraction() == Fraction(1, 1));
    };

    it("can be printed") = [] {
      Fraction a(1, 1);
      ostringstream stream;
      a.out(stream);

      string actual = stream.str();
      string expected = "1/1";

      expect(that % actual == expected);
    };

    it("can be added") = [] {
      {
        Fraction a(1, 5);
        Fraction b(1, 5);
        expect(that % (a + b) == Fraction(2, 5));
      }
      {
        Fraction a(1, 3);
        Fraction b(2, 3);
        expect(that % (a + b) == Fraction(1, 1));
      }
      {
        Fraction a(1, 3);
        Fraction b(2, 7);
        expect(that % (a + b) == Fraction(13, 21));
      }
    };

    it("can be substracted") = [] {
      {
        Fraction a(4, 5);
        Fraction b(1, 5);
        expect(that % (a - b) == Fraction(3, 5));
      }
      {
        Fraction a(1, 1);
        Fraction b(2, 3);
        expect(that % (a - b) == Fraction(1, 3));
      }
      {
        Fraction a(1, 3);
        Fraction b(2, 7);
        expect(that % (a - b) == Fraction(1, 21));
      }
    };

    it("can be multiplied") = [] {
      {
        Fraction actual = Fraction(1, 2) * Fraction(2, 1);
        Fraction expected(1, 1);
        expect(that % actual == expected);
      }
      {
        Fraction actual = Fraction(12, 32) * Fraction(31, 11);
        Fraction expected(12 * 31, 32 * 11);
        expect(that % actual == expected);
      }
      {
        Fraction actual = Fraction(1, 5) * Fraction(0, 1);
        Fraction expected(0, 1);
        expect(that % actual == expected);
      };
    };

    it("can be inversed") = [] {
      expect(that % Fraction(2, 4).inverse() == Fraction(2));
      expect(that % Fraction(3, 2).inverse() == Fraction(2, 3));
      expect(that % Fraction().inverse() == Fraction());
    };

    it("can be divided") = [] {
      {
        Fraction actual = Fraction(1, 3) / Fraction(5, 7);
        Fraction expected(7, 15);
        expect(that % actual == expected);
      }
      {
        Fraction actual = Fraction(7, 3) / Fraction(3, 7);
        Fraction expected(49, 9);
        expect(that % actual == expected);
      }
      {
        Fraction actual = Fraction(1, 17) / Fraction(1, 17);
        Fraction expected(1, 1);
        expect(that % actual == expected);
      };
    };

    it("blocks division by 0") = [] { expect(throws([] { Fraction(1, 0); })); };
  };
}

#endif FRACTION_H
