#pragma once

#include <string>

class Person
{

private:
    std::string firstName;
    std::string lastName;

protected:
    int age;

public:
    Person();
    Person(std::string new_firstName, std::string new_lastName);
    Person(std::string new_firstName, std::string new_lastName, int new_age);

    ~Person();

    void SayHello();
    void displayNameAge() const;
};
