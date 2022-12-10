#include "Kolejka.h"
#include <iostream>

using std::cout;
using std::endl;

using lab0202::Kolejka;

int main() {
  Kolejka k;
  for (int i = 0; i < 10; ++i)
    k.push_back(i);

  cout << k << " -> " << k.size() << endl;

  for (int i = 0; i < 3; ++i)
    cout << "popping " << k.pop_front() << endl;

  cout << k << " -> " << k.size() << endl;

  return 0;
}
