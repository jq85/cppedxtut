#pragma once
#include "Person.h"

//NOTE: default inheritance is 'private'
class Student : public Person
{
private:
  std::string course;

public:
  Student();
  Student(std::string firstName, std::string lastName, int age, std::string course);
  ~Student();

  void displayCourse() const;
};
