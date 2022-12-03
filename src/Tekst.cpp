#include "Tekst.h"
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>

using namespace lab0201;

Tekst::Tekst(const char *data)
    : _len(strlen(data)), data((char *)malloc(strlen(data))) {
  strcpy(this->data, data);
}

Tekst::Tekst(const Tekst &other) : Tekst(other.data) {}

Tekst::~Tekst() { delete[] this->data; }

bool Tekst::operator==(const Tekst &other) const {
  return strcmp(this->data, other.data) == 0;
}

Tekst Tekst::operator()(unsigned int s, unsigned int e) const {
  int len = e - s;
  char *out = (char *)malloc(len + 1);
  strncpy(out, this->data + s, len + 1);
  out[len + 1] = 0;
  return Tekst(out);
}

Tekst Tekst::operator+(const Tekst &other) const {
  int len = this->_len + other._len;
  char *out = (char *)malloc(len + 1);
  strcpy(out, this->data);
  strcpy(out + this->_len, other.data);
  out[len] = 0;

  return Tekst(out);
}

Tekst Tekst::operator-() const {
  char *out = (char *)malloc(this->_len + 1);
  for (auto i = 0; i < this->_len; ++i) {
    int i2 = this->_len - 1 - i;
    out[i] = this->data[i2];
  }

  out[this->_len] = 0;

  return Tekst(out);
}

std::string Tekst::as_str() const { return this->data; };

unsigned int Tekst::len() const { return this->_len; }
