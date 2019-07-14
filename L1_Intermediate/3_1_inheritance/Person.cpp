#include <iostream>
#include "Person.h"


Person::Person()
  //base constructor called first (parent class)
  : firstName{"John"}, lastName{"Snow"}, age{0}
{
  std::cout << "Hello from Person::Person()" << std::endl;
}

Person::Person(std::string new_firstName, std::string new_lastName)
  //base constructor called first (parent class)
  : firstName{new_firstName}, lastName{new_lastName}, age{0}
{
  std::cout << "Hello from Person::Person(std::string new_firstName, std::string new_lastName)" << std::endl;
}

Person::Person(std::string new_firstName, std::string new_lastName, int new_age)
  //base constructor called first (parent class)
  : firstName{new_firstName}, lastName{new_lastName}, age{new_age}
{
  std::cout << "Hello from Person::Person(std::string new_firstName, std::string new_lastName, int new_age)" << std::endl;
}

Person::~Person()
{

}


void Person::SayHello()
{

}

void Person::displayNameAge() const
{
  // std::cout << "first name is " << firstName << ", and age is " << age << std::endl;//NOTE: this-> is not mandatory
  std::cout << "first name is " << this->firstName << ", and age is " << age << std::endl;
}
