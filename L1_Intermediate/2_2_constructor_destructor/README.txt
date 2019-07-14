https://courses.edx.org/courses/course-v1:Microsoft+DEV210.2x+3T2018/course/

# CLASS CONSTRUCTORS
====================
Two features of a constructor:
    - Has the same name as the class.
    - Has no return type.
Let's now turn our attention to the concept of constructors and destructors in our classes.
The topic of constructors was covered briefly in the Introduction to C++ course but we'll offer a review here and expand on the topic of constructors in this lesson,
adding in concepts around destructors.


A constructor is used to initialize data members of a class.
The format of a constructor, at its most basic level, is that it contains the same name as the class itself, has no return type, and may or may not contain a parameter list.
PUBLIC CONSTRUCTOR: Constructors are also, almost always, public although you can have a private constructor for use within the class only.
PRIVATE CONSTRUCTOR: Some developers create a private constructor that is called via a public constructor, for the purposes of initializing private aspects of a class.

OVERLOADING
Classes can have multiple constructors.
Constructors can be overloaded in the same way that functions can be overloaded.

OVERRIDE DEFAULT CONSTRUCTOR
If you don't create a constructor in your class file, the compiler will create a default constructor automatically that will initialize member variables to default values in some compilers,
but other compilers will not use default values. Check your compiler documentation to find out how default constructors work.
The C++ standard indicates that when a compiler follows the standard, the member variables will be initialized to "indeterminate values".
A class has one, and only one, default constructor.
If you do create a default constructor or any other constructor in your class, then the compiler will not create one.
This is an important consideration because if you require or want a default constructor as well as other constructors, then you MUST create your own default constructor.
The default constructor, if provided, is one that does not have any parameters such as:

    class Person
    {
    public:
        Person();
        ~Person();
    };

This code sample demonstrates the template that is provided in Microsoft Visual Studio when creating a new C++ class.
It completes the template with a very simple class definition that includes the class name (Person) and two public members:
  - the default constructor (Person();)
  - and the destructor (~Person();).
Destructors will be covered in the topic on destructors.

There are actually two more, equally important, reasons for defining a default constructor in your classes:

  PARAMS INITIALIZATION
  - First off, compound types (arrays or pointers) that may be defined inside a code block, can have undefined values when initialized to their default values.
    You should ensure that these members are initialized correctly by creating your own default constructor and performing the initialization yourself.

  MEMBER CLASS INITIALIZATION
  - The second reason is a little more complex and arises when your class contains a member that is a class itself.
    The compiler's default constructor is unable to initialize that member.

The following code sample demonstrates the use of three different constructors, one default constructor, one that accepts two arguments and one that accepts three arguments.

**Person.h**

    #pragma once

    #include <string>

    class Person
    {

    private:
        std::string firstName;
        std::string lastName;

        int age;

    public:
        Person();

        Person(std::string fName, std::string lName);

        Person(std::string fName, std::string lName, int age);

        ~Person();

        void SayHello();
    };

**Person.cpp**


    #include "stdafx.h"
    #include "Person.h"
    #include <iostream>

    Person::Person()
    {

    }

    Person::Person(std::string fName, std::string lName)
    {
        this -> firstName = fName;
        this -> lastName = lName;
    }

    Person::Person(std::string fName, std::string lName, int age)
    {
        this -> firstName = fName;
        this -> lastName = lName;

        this -> age = age;
    }


    Person::~Person()
    {
    }

The first constructor is the default constructor.  It has no parameters and because we have not initialized our private member variables,
this constructor will do so with the default values for data types of those member variables.

The second constructor takes two arguments and uses those to initialize the first and last name member variables in the class.
Here is where you need to do a little research on the compiler you are using to determine how the age variable will be initialized.
The reason is, because we do not initialize age in the class when we declared it and because this constructor does not initialize it either,
if you try to use the age variable in an instance of Person, what result will you get? The default constructor will initialize age to a default value (dependent on compiler),
but if you call the second constructor, age may or may not get initialized.

The final constructor takes three arguments to initialize all three member variables.
When you create a new instance of the Person class, you can choose any of these constructors
and the compiler will know which one to use based on the number of arguments you pass in as shown in this code sample.

    #include "stdafx.h"
    #include <iostream>
    #include "Person.h"

    using namespace std;

    int main()
    {

        // create a Person instance using default constructor
        Person *pOne = new Person();

        // Create a Person instance using 2 argument constructor
        Person *pTwo = new Person("Tom", "Thumb");

        // Create a Person instance using 3 argument constructor
        Person *pThree = new Person("Tom", "Thumb", 15);

    return 0;
    }



# CLASS DESTRUCTORS
===================

RELEASE MEMORY
Now that we know how to create objects, and we know that they consume memory while they hang around in our application's executable memory space,
we also need to know how to release that memory when we no longer require the objects.  We do so with the use of a destructor.

In the previous code samples, you may have noticed that the destructor looked a lot like the default constructor, only preceded with a tilde (~).
While it looks similar to the a constructor, having no return type and the same name as the class, except for the tilde,

PARAMS NOT ALLOWED
it's important to note that a destructor CANNOT HAVE ANY ARGUMENTS passed in to it.
Therefore, when writing your own destructors, you should not place arguments between the parentheses for the destructor.

The compiler will handle the actual calling of the destructor when your object expires or the application is closing.

EXTRA LOGIC ALLOWED
If you choose, you can place code inside the destructor.
One reason you may want to do this is to ensure that any resources used by the object, that may not be destroyed or cleaned up, are taken care of in your object's destructor code.



# DYNAMIC MEMORY ALLOCATION AND CLASSES
=======================================

DYNAMICALLY REQUEST MEMORY TO THE OS AS THE APP RUNS
When your application is coded, you may have no idea how many Person objects you will need during the program's lifetime.
As a result, it is likely not possible for you to create sufficient Person objects in code and let the compiler determine how much memory is required for these objects at compile time.
Chances are, you will be creating many objects dynamically as your application code executes.
In order to do so, the application must request memory from the operating system as the application is executing, (dynamically).

NEW & DELETE
This topic discusses the importance of two C++ keywords new and delete.
The keyword new is used to allocate memory for an object at runtime and delete is used to release that memory.
This is also where the constructors and destructors play a big part.
You will also need to change the way you call functions and work with the objects, and we'll cover that in this topic.

NEW
Dynamically allocating memory to hold an object is done with the new keyword.
Using the new keyword means that you must be making the assignment to a pointer of the correct data type. The following code shows a valid and an invalid use of the new keyword.

    Person *pOne = new Person();
    Person per = new Person();//ERROR: "No suitable constructor exists to convert from Person * to Person." (NEW SEEKS A POINTER, NOT AN OBJ VAR)


HEAP MEMORY
POINTER TO NEW OBJECT
In the first line, we declare a pointer called pOne that will hold the memory address of a Person object that will reside in an area of computer memory known as the heap.
When the new keyword is encountered, the computer will set aside enough memory to hold a Person object in memory and assign that memory address to the variable pOne.
WE HAVE NOT CREATED an actual object in memory yet, we have simply asked the computer to allocate sufficient memory to store the object.
How does it know how much memory is needed?  In the case of our Person class, the size is determined by looking at all the member variables, (the classes data),
and based on the data types, it determines the maximum amount of memory required for the object.
No values are assigned at this time either so the compiler uses the maximum size of the specified data type for each member variable.

What happens if our class contains other classes nested within it? The compiler will look at all the members of those classes as well and allocate sufficient memory for them as well.

NEW SEEKS A POINTER
In the second line of code above, we simple declare a variable to be of type Person and call it per.
However, the use of the new keyword is not legal here, at least when using Microsoft Visual Studio 2015.
The error message returned from the compiler indicates that "No suitable constructor exists to convert from Person * to Person."
This clearly indicates that new is seeking a pointer and not an object variable.

Once you have used the new keyword to dynamically create an object in memory,
the way in which you access the member variables and functions is a little different than simply using the dot operator like you might be familiar with in other languages such as C# or Java.
You will now need to use the arrow selection operator to access the members of the class, as shown in the following code sample.

    Person *pOne = new Person("Gerry", "O\'Brien");
    std::cout << pOne->GetLastName() << endl;

In the first line of code, we declare a pointer *pOne and assign it a memory address using the new keyword.
The compiler sets aside memory for the object and assigns the first and last name values to the member variables using one of the constructors in our Person class.
(Refer to previous code samples for the constructors). Because the object has been dynamically allocated with the new keyword,
we must use the arrow selection operator and we see that in the second line of code where we access the GetLastName() member function to retrieve the value stored in the object pointed to by pOne.

DELETE (FOR EVERY NEW)
For every object you create using the new keyword, you also need to use the DELETE keyword to remove the reference to the memory allocated and to release that memory back to the operating system.
Failure to do so results in a memory leak in your application. The memory that is taken up by the object is not released back to the operating system until you call delete or until the application quits.
If you continue to allocate new objects with new and fail to use delete when finished with those objects, the memory used by your application will continue to increase.
The use of delete is rather simple as the following code snippet demonstrates.

    Person *pOne = new Person("Gerry", "O\'Brien");
    std::cout << pOne->GetLastName() << endl;

    // delete object, releasing memory
    delete pOne;

DELETE & DESTRUCTOR & CLEAN UP
(all other called objects must be deleted).
When delete is called on an object, that object's destructor is called.
The destructor is the correct location in code perform CLEAN UP operations on your object and anything that it references.
For example, you might have dynamically declared and used other objects from within your object.
In this case, YOU ARE RESPONSIBLE FOR ENSURING THAT THOSE OTHER OBJECTS ARE ALSO DESTROYED AND THAT THEIR MEMORY IS RELEASED.
You do this by placing the appropriate delete statements inside your object's destructor.

For more information , you can see:
Visual Studio: https://aka.ms/edx-dev210.2x-vs01
