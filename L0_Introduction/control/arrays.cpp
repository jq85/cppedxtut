#include <iostream>

using namespace std;

int main()
{
  // a single-dimensional array of integers with elements zero through nine.
  int arrayName[10];
  std::cout << sizeof(arrayName) << std::endl;
  std::cout << arrayName[0] << std::endl;

  // declares and integer array and assigns values to it.
  // The compiler knows how large to make the array by the number of values in the curly braces
  int arrayName2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::cout << sizeof(arrayName2) << std::endl;
  std::cout << arrayName2[0] << std::endl;

  // declare an array and only initialize some of the elements:
  int arrayName3[10] = {4, 5, 6};
  std::cout << sizeof(arrayName3) << std::endl;
  std::cout << arrayName3[0] << std::endl;

  //number will contain the value 3
  int number = arrayName3[2];
  std::cout << number << std::endl;
  //Iterating Over an Array
  int oldNumbers[] = { 1, 2, 3, 4, 5 };
  for (int i = 0; i < 5; i++)
  {
    int number = oldNumbers[i];
    cout << number << endl;
  }
}
