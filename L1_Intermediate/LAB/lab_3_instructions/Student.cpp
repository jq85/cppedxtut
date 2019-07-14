#include "Student.h"
#include <iostream>

Student::Student()
  : course{"unassigned course"}
{

}

//NOTE: base class Person is called in the constructor, and it catches the params.
Student::Student(const std::string &first_name, const std::string &last_name, const std::string &race, int age, const std::string &course)
  : Person{first_name, last_name, race, age}, course{course}
{

}

/*
* virtual only in .h
* with destructors you never explicitly invoke your parent's destructor. It'll be
* invoked automatically. You can't actually, you're not allowed to invoke a parent destructor.
* the student destructor would be called first to peel off the outer layer of the student
* object if you like and then automatically the compiler will call the
* base destructor afterwards. So destruction is always the reverse order of construction
*/
Student::~Student()
{

  std::cout << "Goodbye from the Student destructor" << std::endl;
}


void Student::OutputIdentity()
{
  std::cout << "I am student" << std::endl;
}

void Student::OutputAge()
{
  std::cout << "I am ";
  Person::OutputAge();
  std::cout << " years old." << std::endl;
}
