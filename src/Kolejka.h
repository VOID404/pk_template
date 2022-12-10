
#ifndef KOLEJKA_H
#define KOLEJKA_H

#include <compare>
#include <iostream>

namespace lab0202 {

struct Node {
  int data;
  Node *prev;
  Node *next;
};

class Lista {
private:
  Node *first;
  Node *last;

public:
  Lista();
  ~Lista();
  void push_back(int n);
  void push_front(int n);
  int pop_back();
  int pop_front();
  int size() const;

  friend std::ostream &operator<<(std::ostream &os, const Lista &l);
};

class Kolejka : public Lista {
public:
  int pop_back() = delete;
  void push_front() = delete;
};

} // namespace lab0202

#endif /* KOLEJKA_H */
