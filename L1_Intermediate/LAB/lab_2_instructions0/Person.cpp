// #include "stdafx.h"
#include "Person.h"
#include <iostream>


P::Person::Person()
{

}

P::Person::Person(std::string fName, std::string lName)
{
    firstName = fName;
    lastName = lName;
}

P::Person::Person(std::string fName, std::string lName, int age)
{
    firstName = fName;
    lastName = lName;

    age = age;
}


P::Person::~Person()
{
}

void P::Person::SetFirstName(std::string fName)
{
    this->firstName = fName;
}

std::string P::Person::GetFirstName()
{
    return this->firstName;
}

void P::Person::SetLastName(std::string lName)
{
    this->lastName = lName;
}

std::string P::Person::GetLastName()
{
    return this->lastName;
}

void P::Person::SetAge(int age)
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

int P::Person::GetAge()
{
    return this->age;
}


void P::Person::SetAddress(std::string address)
{
  this->address = address;
}

std::string P::Person::GetAddress()
{
  return this->address;
}


void P::Person::SetCity(std::string city)
{
  this->city = city;
}

std::string P::Person::GetCity()
{
  return this->city;
}


void P::Person::SetPhone(int phone)
{
  this->phone = phone;
}

int P::Person::GetPhone()
{
  return this->phone;
}


void P::Person::SayHello()
{
    std::cout << "Hello" << std::endl;
}
