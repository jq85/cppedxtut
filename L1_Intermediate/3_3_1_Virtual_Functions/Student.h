#pragma once
#include "Person.h"

class Student : public Person
{
private:
    std::string course;

public:
  Student();
  Student(const std::string &name, int age, const std::string &course);
  /*
  * When you override
  * methods from the base class it's good practice to put the virtual keyword
  * again in here, in the derived header file
  */
  virtual ~Student();
  virtual void display() const;     // Override function from base class.
};
