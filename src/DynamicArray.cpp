#include "DynamicArray.h"

using namespace lab01;

DynamicArray::DynamicArray(const int length, int val) : length(length) {
  arr = new int[length];
  for (auto i = 0; i < length; ++i) {
    arr[i] = val;
  }
}

DynamicArray::DynamicArray(const DynamicArray &other) : length(other.length) {
  arr = new int[length];
  for (auto i = 0; i < length; ++i) {
    arr[i] = other.arr[i];
  }
}

DynamicArray::~DynamicArray() { delete[] arr; }

const int DynamicArray::get_length() { return length; }
const int *DynamicArray::get_arr() { return arr; }
