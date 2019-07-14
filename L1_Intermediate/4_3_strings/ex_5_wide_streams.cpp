#include <sstream>// For std::stringstream.
#include <string> // For std::string.
#include <iostream>   // For std::cout etc. 

int main()
{
  // Write to stream.
  std::stringstream stream;
  stream << "Jane" << " " << 42 << " " << 15000 << std::endl;

  // read from stream.
  std::string name;
  int age;
  double salary;
  stream >> name >> age >> salary;

  std::cout
  << "Name: " << name << std::endl
  << "Age: " << age << std::endl
  << "Salary:" << salary << std::endl;

  return 0;
}
