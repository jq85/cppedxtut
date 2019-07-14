// #include "stdafx.h"
#include <iostream>
#include "Student.h"
#include "Person.h"


/*
* notice that we don't mention the base class. If you don't mention the base
* class constructor, the compiler will automatically invoke the no argument
* constructor anyway. It'll always invoke the base constructor whether you want it
* or not. You can't avoid it. So if you don't mention the base class there, it will
* invoke the default constructor in the base class, and if your base class
* doesn't have a default constructor then you have a compiler error. So this will
* invoke the default constructor from Person to initialize the name and age with
* artificial values.
*/
Student::Student()
  : course{"Engineering course"}
{
  std::cout << "Hello from Student::Student()" << std::endl;
}


Student::Student(std::string firstName, std::string lastName, int age, std::string course)
  : Person{firstName, lastName, age}, course{course}
{
  std::cout << "Hello from Student::Student(std::string firstName, std::string lastName, int age, std::string course)" << std::endl;
}


Student::~Student()
{
}


void Student::displayCourse() const
{
  // std::cout << "course is " << this->course << std::endl;//NOTE: this-> is not mandatory
  std::cout << "course is " << course << std::endl;
}

// firstName = "Tom";//WARNING: this line will cause the compiler error:[ 'firstName' does not name a type ]
