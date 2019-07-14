#include <iostream>
#include "Utilities.h"

using namespace std;

int main()
{
  int x = 1;
  int y = 2;
  int x_plus_y = Sum(x, y);
  cout << "x_plus_y " << x_plus_y << endl;
  char char_x_plus_y = Sum('a', 'h');
  cout << "char_x_plus_y " << char_x_plus_y << endl;
}
