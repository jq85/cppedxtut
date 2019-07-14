#include <iostream>

using namespace std;

/**
 * Strings are a series of characters.
 * C++ represents strings in one of two ways.
 * The first maintains backward compatibility with the C language and represents the string as a character array.
 * There is one aspect to a C-style string that is important to note.
 * The last character of every string you store is the null character string, typically represented by the ASCII code for 0 which is \0.
 * This is necessary so that the compiler knows when the string ends. An example demonstrates a C-style string stored in a character array:
 */
int main()
{
  // C-compatible style 1:
  char isAString[6] = { 'A', 'b', 'c', 'd', 'e', '\0'};
  char isNotAString[5] = { 'A', 'b', 'c', 'd', 'e'};
  cout << isAString << endl;
  cout << isNotAString << endl;

  // C-compatible style 2:
  /** An alternative method of declaring a character array for use as a string is to simply initialize it with a string literal.
  * A string literal is a sequence of characters enclosed in the double quotes
  */
  char isAString2[6] = "Hello";
  char isAnotherString[] = "Array size is inferred";
  cout << isAString2 << endl;
  cout << isAnotherString << endl;

  // C++ style: The string Class
  /**
  *
  */
  string myString = "Hello!";
  std::string myNewString = "Less typing";
  cout << myString << endl;
  cout << myNewString << endl;
}
