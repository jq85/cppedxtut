#include <sstream>// For std::stringstream.
#include <string> // For std::string.
#include <iostream>   // For std::cout etc.

int main()
{
  // Create a stringstream object.
  std::stringstream stream;

  // Set the string content for a stringstream.
  stream.str("Jane 42 15000");

  // Get the content from a stringstream.
  std::cout << "Content of string stream: " << stream.str() << std::endl;

  //NOTE: We can still use the stringstream as stream of formatted data.
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
