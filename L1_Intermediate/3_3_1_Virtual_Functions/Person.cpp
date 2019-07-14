#include "Person.h"
#include <iostream>

Person::Person()
  : name{"unknown name"}, age{0}
{
    // Any destruction code for Person object.
}

Person::Person(const std::string &name, int age)
  : name{name}, age{age}
{
    // Any destruction code for Person object.
}

/*
* virtual only in .h
* with destructors you never explicitly invoke your parent's destructor. It'll be
* invoked automatically. You can't actually, you're not allowed to invoke a parent destructor.
* the student destructor would be called first to peel off the outer layer of the student
* object if you like and then automatically the compiler will call the
* base destructor afterwards. So destruction is always the reverse order of construction
*/
Person::~Person()
{
    // Any destruction code for Person object.
    std::cout << "Goodbye from the Person destructor" << std::endl;
}

/*
* virtual keyword only in .h
*/
void Person::display() const
{
    std::cout << name << ", " << age << std::endl;
}
