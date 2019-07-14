#pragma once

#include <string>

class Person
{

private:
    std::string firstName;
    std::string lastName;
    int age;

    std::string address;
    std::string city;
    int phone;

public:

    int count;
    Person();

    Person(std::string fName, std::string lName);

    Person(std::string fName, std::string lName, int age);

    ~Person();

    void SetFirstName(std::string fName);
    std::string GetFirstName();

    void SetLastName(std::string lName);
    std::string GetLastName();

    void SetAge(int age);
    int GetAge();

    void SetFirstName(std::string fName);
    std::string GetFirstName();

    void SetLastName(std::string lName);
    std::string GetLastName();

    void SetAge(int age);
    int GetAge();

    void SetAddress(std::string address);
    std::string GetAddress();

    void SetCity(std::string city);
    std::string GetCity();

    void SetPhone(int phone);
    int GetPhone();

    void SayHello();

};
