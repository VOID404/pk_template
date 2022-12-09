#ifndef SET_H
#define SET_H

class Set {
private:
  int *data;
  int _size;
  int _capacity;

  void grow();

public:
  bool contains(int n) const;

  Set(int capacity = 16);
  Set(Set const &other);
  ~Set();
  void push(int n);
  void pop(int n);

  Set &operator*=(const Set &other);
  Set &operator+=(const Set &other);
  Set &operator-=(const Set &other);

  Set operator*(const Set &other) const;
  Set operator+(const Set &other) const;
  Set operator-(const Set &other) const;
};

#endif /* SET_H */
