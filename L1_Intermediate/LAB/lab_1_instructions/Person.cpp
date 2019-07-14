#include <string>
#include "Person.h"
#include <iostream>

// zero argument constructor
Person::Person()
{

}

// overloaded two argument constructor
Person::Person(std::string firstName, std::string lastName)
{
  _firstName = firstName;
  _lastName = lastName;
}

// overloaded three argument constructor
Person::Person(std::string firstName, std::string lastName, int age)
{
  _firstName = firstName;
  _lastName = lastName;
  _age = age;
}

// destructor
Person::~Person()
{
  std::cout << "Person destructor called " << std::endl;
}


//getters and setters
void Person::setFirstName(std::string firstName)
{
  this->_firstName = firstName;
}

std::string Person::getFistName()
{
  return this->_firstName;
}


void Person::setLastName(std::string lastName)
{
  this->_lastName = lastName;
}

std::string Person::getLastName()
{
  return this->_lastName;
}


void Person::setAge(int age)
{
  _age = age;
}

int Person::getAge()
{
  return _age;
}


void Person::SayHello()
{
  std::cout << "Hello, I am " << this->getFistName() << std::endl;
  // std::cout << "Hello, I am " << this->_firstName << std::endl;
}
