#include <iostream>

using namespace std;

int main()
{
  /*
  for ([initializer(s)]; [condition]; [iterator])
  {
     // code to repeat goes here
  }
  */
  cout << "i  j" << endl;
  for (int i = 0, j=9; i < 10; i++, j--)
  {
      cout << i << "  " << j << endl;
  }
}
