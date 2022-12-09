#include "Set.h"
#include <algorithm>
#include <cstring>

Set::Set(int capacity)
    : _capacity(capacity), _size(0), data(new int[capacity]) {}

Set::Set(Set const &other)
    : _capacity(other._capacity), _size(other._size),
      data(new int[other._capacity]) {
  memcpy(this->data, other.data, other._size);
}

Set::~Set() { delete[] this->data; }

void Set::push(int n) {
  if (this->contains(n))
    return;

  if (this->_size == this->_capacity)
    this->grow();

  this->data[this->_size++] = n;
}

void Set::pop(int n) {
  int shift = 0;
  for (int i = 0; i + shift < _size; ++i) {
    if (data[i] == n) {
      shift = 1;
    }
    data[i] = data[i + shift];
  }

  if (shift == 1)
    --_size;
}

void Set::grow() {
  int new_capacity = this->_capacity * 2;
  int *new_data = new int[new_capacity];

  memcpy(new_data, this->data, this->_size);
  delete[] this->data;

  this->data = new_data;
  this->_capacity = new_capacity;
}

bool Set::contains(int n) const {
  for (int i = 0; i < _size; ++i)
    if (data[i] == n)
      return true;

  return false;
}

Set Set::operator+(const Set &other) const {
  Set sum(*this);
  for (int i = 0; i < other._size; ++i)
    sum.push(other.data[i]);

  return sum;
}

// Set Set::operator-(const Set &other) const {
//   Set out(*this);
//   for (int i = 0; i < other._size; ++i)
//     out.pop(other.data[i]);

//   return out;
// }
Set Set::operator-(const Set &other) const {
  Set out;
  for (int i = 0; i < this->_size; ++i)
    if (!other.contains(data[i]))
      out.push(data[i]);

  return out;
}

Set Set::operator*(const Set &other) const {
  Set out;
  for (int i = 0; i < this->_size; ++i)
    if (other.contains(data[i]))
      out.push(data[i]);

  return out;
}
