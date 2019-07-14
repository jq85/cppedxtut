https://courses.edx.org/courses/course-v1:Microsoft+DEV210.2x+3T2018/course/

# FRIEND FUNCTIONS
==================

In your implementation of the Person base class, which attributes does the derived class Student have access to?
Select all that apply.
  YES   first_name (public)
  YES   phone (protected)
  NO    age (private)
  YES   last_name (public)

A class can define an external function as a friend function.
This allows the friend function to access all the members of the class, including private members.
Friend functions are non-members, which means they don't receive a "this" pointer.
Consequently, they must require an explicit parameter to access an object.

The following example shows how a class can declare an external function named SomeExternalFunction() as a friend function of the class. SomeExternalFunction() receives a reference parameter that identifies the object the function will deal with:

**MyClass.h**

    class MyClass
    {
        friend void SomeExternalFunction(MyClass & targetObject);

        // Data members and member functions, as required.
        ...
    };

The following code snippet shows how you might implement SomeExternalFunction(). Typically, you put friend function implementations in the same source file as member function implementations, because they are all part of the semantic meaning of the same class. However you don't prefix friend functions with the ClassName:: syntax, because they are not members of the class:

**MyClass.cpp**

    #include "MyClass.h"

    void SomeExternalFunction(MyClass & targetObject)
    {
        // Access any members on the target object, i.e. public, private, or protected members.
        ...
    }
