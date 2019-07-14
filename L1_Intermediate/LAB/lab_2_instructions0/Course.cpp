// #include "stdafx.h"
#include "Course.h"
// #include "Student.h"
// #include "Teacher.h"

#include <iostream>


Course::Course()
{

}

Course::Course(std::string n_name)
{
    this->name = n_name;
}


Course::~Course()
{
}

void Course::SetName(std::string n_name)
{
    this->name = n_name;
}

std::string Course::GetName()
{
    return this->name;
}

void Course::addStudent(S::Student student)
{
  // if(this->students_idx < this->students_max)
  // {
  //   this->students_idx++;
  //   this->students[this->students_idx] = student;
  // }
  this->students[1] = student;
}


void Course::addTeacher(T::Teacher teacher)
{
  this->teachers[1] = teacher;
}
