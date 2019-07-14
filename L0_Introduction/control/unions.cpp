#include <iostream>

using namespace std;

int main()
{
  union numericUnion
  {
    int intValue;
    long longValue;
    double doubleValue;
  };

  numericUnion myUnion;
  myUnion.intValue = 3;
  cout << myUnion.intValue << endl;
  myUnion.doubleValue = 4.5;
  cout << myUnion.doubleValue << endl;
  cout << myUnion.intValue;
  cout << endl;
  std::cout << sizeof(numericUnion) << std::endl;

}
