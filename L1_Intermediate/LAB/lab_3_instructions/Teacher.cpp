#include "Teacher.h"
#include <iostream>

Teacher::Teacher()
  : course{"unassigned course"}
{

}

//NOTE: base class Person is called in the constructor, and it catches the params.
Teacher::Teacher(const std::string &first_name, const std::string &last_name, const std::string &race, int age, const std::string &course)
  : Person{first_name, last_name, race, age}, course{course}
{

}

/*
* virtual only in .h
* with destructors you never explicitly invoke your parent's destructor. It'll be
* invoked automatically. You can't actually, you're not allowed to invoke a parent destructor.
* the Teacher destructor would be called first to peel off the outer layer of the Teacher
* object if you like and then automatically the compiler will call the
* base destructor afterwards. So destruction is always the reverse order of construction
*/
Teacher::~Teacher()
{

  std::cout << "Goodbye from the Teacher destructor" << std::endl;
}


void Teacher::OutputIdentity()
{
  std::cout << "I am a teacher" << std::endl;
}

void Teacher::OutputAge()
{
  std::cout << "I am teacher and ";
  Person::OutputAge();
}
