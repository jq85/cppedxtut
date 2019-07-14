#pragma once

#include <string>

class Person
{

private:
    std::string firstName;
    std::string lastName;

// protected:

    int age;


public:


    Person();

    Person(std::string fName, std::string lName);

    Person(std::string fName, std::string lName, int age);

    ~Person();

    void SetFirstName(std::string fName);
    std::string GetFirstName();

    void SetLastName(std::string lName);
    std::string GetLastName();

    /*
     setAge() and getAge() are no longer present in the Person class file.
     We could have left them in Person and forced
     or allowed overridden functions in the derived classes
     but in this instance, we are just demonstrating the use of protected access.
    */
    //setAge();
    //getAge();

    void SayHello();

};
