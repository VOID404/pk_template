#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

namespace lab01 {

class DynamicArray {
private:
  const int length;
  int *arr;

public:
  DynamicArray(const int length, const int val);
  DynamicArray(const DynamicArray &other);
  ~DynamicArray();

  const int get_length();
  const int *get_arr();
};

} // namespace lab01

#endif
