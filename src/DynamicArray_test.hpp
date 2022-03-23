#ifndef DYNAMIC_ARRAY_TEST_H
#define DYNAMIC_ARRAY_TEST_H

#include "DynamicArray.h"
#include "ut.hpp"

using std::ostringstream;
using std::string;

void test_dynamic_array() {
  using namespace boost::ut;
  using namespace boost::ut::spec;

  describe("dynamic array") = [] {
    using lab01::DynamicArray;
    it("constructs correctly") = [] {
      DynamicArray arr(10, 5);

      expect(that % arr.get_length() == 10);

      auto arr_ptr = arr.get_arr();
      for (int i = 0; i < 10; ++i) {
        expect(that % arr_ptr[i] == 5);
      }
    };
  };
}

#endif
