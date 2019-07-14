#include <string>
#include "Person.h"
#include <iostream>

int main()
{
  Person *person = new Person("John", "Snow", 22);

  std::cout << "Fist name of person = " << person->getFistName() << std::endl;
  std::cout << "Memory address of person = " << &person << std::endl;

  person->SayHello();

  //in this case, we're dealing with a reference variable for class.
  //So, a destructor will actually be called once this delete statement is executed.
  delete person;

  return 0;
}
