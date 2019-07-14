#include <sstream>// For std::stringstream.
#include <string> // For std::string.
#include <iostream>   // For std::cout etc.

int main()
{
  std::string name;
  int age;
  double salary;
  // Create a stringstream object and the string to write to.
  std::string str = "********************";
  std::stringstream stream(str);

  // OVERRIDING STRINGS
  // Do some output.
  // NOTE: stream intakes every chunk and concatenates into a single string stream
  stream << "Jane" << " " << 42 << " " << 15000;

  // See the effect.
  std::cout << stream.str() << std::endl;


  // PARSING STRINGS
  // Create a std::stringstream object to parse an existing formatted string to extract values.
  // Create a stringstream object to read from an existing string.
  str = "Jane 42 15000";

  // Read formatted data from stringstream.

  // NOTE: stream outputs chunk by chunk
  stream >> name >> age >> salary;

  std::cout
      << "Name: " << name << std::endl
      << "Age: " << age << std::endl
      << "Salary:" << salary << std::endl;

  return 0;
}
