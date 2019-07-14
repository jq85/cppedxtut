#pragma once

#include <string>
#include "Student.h"
#include "Teacher.h"

class Course
{

private:
    std::string name;
    S::Student students[10];
    int students_idx;
    int students_max = 10;
    T::Teacher teachers[2];
    int teachers_idx;
    int teachers_max = 2;

public:

    Course();

    Course(std::string n_name);

    ~Course();

    void SetName(std::string n_name);
    std::string GetName();

    void addStudent(S::Student student);
    void addTeacher(T::Teacher teacher);

};
