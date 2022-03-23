#include "DynamicArray_test.hpp"
#include "Fraction.h"
#include "Fraction_test.hpp"
#include "ut.hpp"
#include <iostream>
#include <sstream>

using std::ostringstream;
using std::string;

int main() {
  test_fractions();
  test_dynamic_array();
  return 0;
}
