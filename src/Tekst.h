#ifndef TEKST_H
#define TEKST_H

#include <compare>
#include <iostream>
#include <stdexcept>
#include <string>

namespace lab0201 {

class Tekst {
private:
  char *data;
  unsigned int _len;

public:
  Tekst(const char *data = nullptr);
  Tekst(const Tekst &other);
  ~Tekst();

  unsigned int len() const;
  bool operator==(const Tekst &other) const;
  Tekst operator+(const Tekst &other) const;
  Tekst operator-() const;
  Tekst operator()(unsigned int s, unsigned int e) const;

  std::string as_str() const;
};
} // namespace lab0201

#endif /* TEKST_H */
