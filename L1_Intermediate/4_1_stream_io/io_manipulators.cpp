#include <iomanip>// Necessary for parameterized manipulators.
#include <iostream>   // Necessary for general stream I/O definitions.

int main()
{
  std::cout << std::setw(10) << -123.45 << std::endl;

  const char * message = "wibble";
  std::cout << "[" << std::setw(10) << message << "]" << std::endl;

  return 0;
}
