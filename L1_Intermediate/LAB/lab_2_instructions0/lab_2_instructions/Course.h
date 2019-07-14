#pragma once

#include <string>

class Course
{

private:
    std::string firstName;
    std::string lastName;

    int age;

public:

    int count;
    Course();

    Course(std::string fName, std::string lName);

    Course(std::string fName, std::string lName, int age);

    ~Course();

    void SetFirstName(std::string fName);
    std::string GetFirstName();

    void SetLastName(std::string lName);
    std::string GetLastName();

    void SetAge(int age);
    int GetAge();

    void SayHello();

};
