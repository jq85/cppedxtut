#include <sstream>// For std::stringstream.
#include <string> // For std::string.
#include <iostream>   // For std::cout etc.

int main()
{
  // WRITE ONLY
  // Create an ostringstream object, which supports write-only operations.
  std::ostringstream stream1;

  stream1 << "Jane" << " " << 42 << " " << 15000 << std::endl;

  // READ ONLY
  // Create an istringstream object, which supports read-only operations.
  std::istringstream stream2(stream1.str());

  // Read formatted data from istringstream.
  std::string name;
  int age;
  double salary;
  stream2 >> name >> age >> salary;

  std::cout
      << "Name: " << name << std::endl
      << "Age: " << age << std::endl
      << "Salary:" << salary << std::endl;

  return 0;
}
