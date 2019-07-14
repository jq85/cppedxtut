#include "Rectangle.h"
#include <iostream>

using namespace std;

int main()
{
  // no initialization means it takes whatever value there is in that memory region.
  int x;
  // default initialization to 0
  int y{}; // ==> y == 0
  // initialization to a specific value
  int z{1}; // ==> z == 1

  Rectangle uninitialized;
  Rectangle value{};
  Rectangle aggregate{2, 3};

  cout << uninitialized._width << endl;
  uninitialized._width = 123;
  cout << uninitialized._width << endl;

  cout << value._width << endl;
  value._width = 2;
  value._height = 3;
  cout << value._width << endl;

  cout << aggregate._width << endl;

  return 0;
}
