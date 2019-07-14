// #include "stdafx.h"
#include "Student.h"
#include <iostream>

S::Student::Student()
{

}

S::Student::Student(std::string fName, std::string lName)
{
    firstName = fName;
    lastName = lName;
}

S::Student::Student(std::string fName, std::string lName, int age)
{
    firstName = fName;
    lastName = lName;

    age = age;
}


S::Student::~Student()
{
}


void S::Student::SetFirstName(std::string fName)
{
    this->firstName = fName;
}

std::string S::Student::GetFirstName()
{
    return this->firstName;
}


void S::Student::SetLastName(std::string lName)
{
    this->lastName = lName;
}

std::string S::Student::GetLastName()
{
    return this->lastName;
}


void S::Student::SetAge(int age)
{
    if (age > 0)
    {
        this->age = age;
    }
    else
    {
        std::cout << "Please enter a valid age" << std::endl;
    }
}

int S::Student::GetAge()
{
    return this->age;
}


void S::Student::SetAddress(std::string address)
{
  this->address = address;
}

std::string S::Student::GetAddress()
{
  return this->address;
}


void S::Student::SetCity(std::string city)
{
  this->city = city;
}

std::string S::Student::GetCity()
{
  return this->city;
}


void S::Student::SetPhone(int phone)
{
  this->phone = phone;
}

int S::Student::GetPhone()
{
  return this->phone;
}


void S::Student::SayHello()
{
    std::cout << "Hello" << std::endl;
}

void S::Student::SitInClass()
{
  std::cout << "Sitting in main theater" << std::endl;
}
