#include <sstream>// For std::stringstream.
#include <string> // For std::string.
#include <iostream>   // For std::cout etc.

int main()
{
  std::wstringstream stream;

  stream << "Jane" << " " << 42 << " " << 15000 << std::endl;

  std::wstring formattedString = stream.str();
  std::wcout << formattedString;

  std::wstring name;
  int age;
  double salary;
  stream >> name >> age >> salary;

  std::wcout
      << "Name: " << name << std::endl
      << "Age: " << age << std::endl
      << "Salary:" << salary << std::endl;

  return 0;
}
