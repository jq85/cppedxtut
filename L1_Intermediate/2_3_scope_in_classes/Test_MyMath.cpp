#include <iostream>
#include "MyMath.h"
#include "math.h"

using namespace std;
// using namespace MyMath;

int main()
{
  double sq = sqrt(24);
  cout << "Square root of 24 is " << sq << endl;

  long p = pow(2, 4);
  cout << p << endl;

  int d = MyMath::Math::pow(2, -3);
  cout << d << endl;
  d = MyMath::Math::pow(2, 3);
  cout << d << endl;

  return 0;
}
