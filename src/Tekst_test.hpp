#ifndef TEKST_TEST_H
#define TEKST_TEST_H

#include "Tekst.h"
#include "ut.hpp"
#include <iostream>
#include <sstream>
#include <string>

using std::ostringstream;
using std::string;

void test_tekst() {
  using namespace boost::ut;
  using namespace boost::ut::spec;

  describe("Tekst") = [] {
    using lab0201::Tekst;
    it("Initializes correctly") = [] {
      string expected = "Hello World!";
      string expected2 = "Hello ansi C";
      Tekst txt1(expected.c_str());
      Tekst txt2(expected.c_str());
      Tekst txt3(expected2.c_str());

      expect(txt1 == txt2);
      expect(txt1 != txt3);
      expect(that % txt1.len() == expected.length());
      expect(that % txt1.as_str() == expected);
    };

    it("Combines correctly") = [] {
      string a = "abc";
      string b = "def";
      string comb = "abcdef";

      Tekst txt1(a.c_str());
      Tekst txt2(b.c_str());
      Tekst tcomb = txt1 + txt2;
      expect(that % tcomb.as_str() == comb);
    };

    it("Substring correctly") = [] {
      string a = "Hello World!";
      string b = "ello";

      Tekst txt1(a.c_str());
      auto txt2 = txt1(1, 5);

      expect(that % txt2.as_str() == b);
    };

    it("Reverses correctly") = [] {
      string a = "abc";
      string b = "cba";

      Tekst txt1(a.c_str());
      Tekst txt2 = -txt1;
      expect(that % txt2.as_str() == b);
      expect(that % txt1.len() == txt2.len());
    };
  };
}

#endif // TEKST_TEST_H
