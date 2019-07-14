#include <iostream>

using namespace std;

/*
* Here I only declare the function prototypes,
* it is like a promise to the compiler that the functions below will be described later.
* This is akin to declare them in a .h header file.
* When declaring a function, you specify its storage class, return type, name, and parameters.
*/
int Sum(int x, int y);
int Sum(char x, char y);
int Sum(int x, int y, int z);

int main()
{
  int x = 1;
  int y = 2;
  int x_plus_y = Sum(x, y);
  cout << "x_plus_y " << x_plus_y << endl;
  char char_x_plus_y = Sum('a', 'h');
  cout << "char_x_plus_y " << char_x_plus_y << endl;
}


/*
* Here the functions are described.
*/
int Sum(int x, int y)
{
  return x + y;
}

//
int Sum(char x, char y)
{
  return x + y;
}

//
int Sum(int x, int y, int z)
{
  return x + y + z;
}
