// #include "stdafx.h"
#include "Teacher.h"
#include <iostream>

T::Teacher::Teacher()
{

}

T::Teacher::Teacher(std::string fName, std::string lName)
{
    firstName = fName;
    lastName = lName;
}

T::Teacher::Teacher(std::string fName, std::string lName, int age)
{
    firstName = fName;
    lastName = lName;

    age = age;
}


T::Teacher::~Teacher()
{
}

void T::Teacher::SetFirstName(std::string fName)
{
    this->firstName = fName;
}

std::string T::Teacher::GetFirstName()
{
    return this->firstName;
}

void T::Teacher::SetLastName(std::string lName)
{
    this->lastName = lName;
}

std::string T::Teacher::GetLastName()
{
    return this->lastName;
}

void T::Teacher::SetAge(int age)
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

int T::Teacher::GetAge()
{
    return this->age;
}


void T::Teacher::SetAddress(std::string address)
{
  this->address = address;
}

std::string T::Teacher::GetAddress()
{
  return this->address;
}


void T::Teacher::SetCity(std::string city)
{
  this->city = city;
}

std::string T::Teacher::GetCity()
{
  return this->city;
}


void T::Teacher::SetPhone(int phone)
{
  this->phone = phone;
}

int T::Teacher::GetPhone()
{
  return this->phone;
}


void T::Teacher::SayHello()
{
    std::cout << "Hello" << std::endl;
}

void T::Teacher::GradeStudent()
{
  std::cout << "Student graded" << std::endl;
}

void SitInClass()
{
  std::cout << "Sitting at front of class" << std::endl;
}
