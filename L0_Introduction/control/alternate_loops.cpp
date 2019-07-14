#include <iostream>

using namespace std;

int main()
{
  bool alternate = true;

  for (int x = 0; x < 8; x++)
  {
      for (int y = 0; y < 4; y++)
      {
          if (alternate)
          {
              cout << "X ";
              cout << "O ";

          }
          else
          {
              cout << "O ";
              cout << "X ";

          }
      }
      alternate = !alternate;

      cout << endl;
  }
}
