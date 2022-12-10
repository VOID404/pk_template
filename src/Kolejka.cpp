#include "Kolejka.h"
#include <ostream>
#include <stdexcept>

using namespace lab0202;

std::ostream &lab0202::operator<<(std::ostream &os, const Lista &l) {
  os << "[ ";
  for (auto elem = l.first; elem != nullptr; elem = elem->next)
    os << elem->data << ' ';
  return os << ']';
}

Lista::Lista() : first(nullptr), last(nullptr) {}
Lista::~Lista() {
  for (auto elem = first; elem != nullptr;) {
    auto next = elem->next;
    delete elem;
    elem = next;
  }
}

void Lista::push_back(int n) {
  auto nn = new Node{
      .data = n,
      .prev = last,
      .next = nullptr,
  };

  if (last != nullptr)
    last->next = nn;
  else
    first = nn;

  last = nn;
}

void Lista::push_front(int n) {
  auto nn = new Node{
      .data = n,
      .prev = nullptr,
      .next = first,
  };

  if (first != nullptr)
    first->prev = nn;
  else
    last = nn;

  first = nn;
}

int Lista::pop_back() {
  if (last == nullptr)
    throw std::runtime_error("Cannot pop from empty list");

  auto n = last->prev;
  auto o = last->data;
  delete last;
  last = n;
  return o;
}

int Lista::pop_front() {
  if (first == nullptr)
    throw std::runtime_error("Cannot pop from empty list");

  auto n = first->next;
  auto o = first->data;
  delete first;
  first = n;
  return o;
}

int Lista::size() const {
  int i = 0;
  for (auto elem = first; elem != nullptr; elem = elem->next)
    ++i;
  return i;
}
