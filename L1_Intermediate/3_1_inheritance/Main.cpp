// #include "stdafx.h"
#include "Person.h"
#include "Student.h"

int main()
{
  //Create a student object using the NON-parametrized constructor:
  Student student1;//NOTE: no arg constructor
  // student1.firstName = "Tom"; //WARNING: this line will generate the compiler error: [ 'std::__cxx11::string Person::firstName' is private within this context .\Person.h:9:17: note: declared private here ]
  student1.SayHello();
  student1.displayNameAge();
  student1.displayCourse();

  //Create a student object using the parametrized constructor:
  Student student2{"John", "Snow", 33, "Physics"};
  student2.SayHello();
  student2.displayNameAge();
  student2.displayCourse();

  return 0;
}
