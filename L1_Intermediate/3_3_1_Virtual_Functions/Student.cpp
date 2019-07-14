#include "Student.h"
#include <iostream>

Student::Student()
  : course{"unassigned course"}
{

}

//NOTE: base class Person is called in the constructor, and it catches the params.
Student::Student(const std::string &name, int age, const std::string &course)
  : Person{name, age}, course{course}
{

}

/*
* virtual only in .h
* with destructors you never explicitly invoke your parent's destructor. It'll be
* invoked automatically. You can't actually, you're not allowed to invoke a parent destructor.
* the student destructor would be called first to peel off the outer layer of the student
* object if you like and then automatically the compiler will call the
* base destructor afterwards. So destruction is always the reverse order of construction
*/
Student::~Student()
{

  std::cout << "Goodbye from the Student destructor" << std::endl;
}

// virtual only in .h
void Student::display() const
{
    //To leverage the existing functionality of the base-class version of the function
    // Call base-class version of display(), to display person-related info.
    //NO SUPER::
    //SPECIFY BASE CLASS
    Person::display();
    /*
    * Notice that you have to specify the name of the base
    * class when you override methods like this. Some other languages like
    * C# and Java, use keywords such as base or "super" to invoke a superclass method but
    * in C++ you have to give it the base class, the actual name of it, and the reason for
    * that is because C++ supports multiple inheritance. So you could theoretically
    * inherit for multiple base classes both of which happened to have a display()
    * function.
    */

    // Now display the student-related info.
    std::cout << course << std::endl;
}
