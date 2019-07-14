#pragma once
#include "Person.h"

class Student : public Person
{
private:
    std::string course;

public:
  Student();
  Student(const std::string &first_name, const std::string &last_name, const std::string &race, int age, const std::string &course);
  /*
  * When you override
  * methods from the base class it's good practice to put the virtual keyword
  * again in here, in the derived header file
  */
  virtual ~Student();
  virtual void OutputIdentity();
  virtual void OutputAge();

};
