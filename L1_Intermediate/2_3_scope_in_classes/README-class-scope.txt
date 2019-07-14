https://courses.edx.org/courses/course-v1:Microsoft+DEV210.2x+3T2018/course/


# WHAT IS CLASS SCOPE?
======================
Class scope permits the creation of class level functions and variables that will not conflict with functions or variables of the same name in a different class.

Class scope plays into calling classes with functions that have the
same names or even dealing with functions that have the same member
variables again the class scope means that those member variables
and functions are hidden inside the class in terms of the compiler
knowing which one to call.
So they're not technically hidden because their public
but when you call a function on a class. The scope
is based on the class name or the object that it's pointing to
when the compiler looks for which function it is to call.


When we discuss scope in the context of classes, we are referring to the names of member variables and member functions found within the class definition.

The scope of a class within a namespace or program file is not covered in this topic.

Within a class, all of the member variables and functions are available to the class's functions.
ACCESS MODIFIERS: Note that the members of a class can have access modifiers too such as private and public but that determines their visibility from outside the class.
All public and private members are available within the class to functions inside the class.

When accessing the members of a class, you use the object name followed by either a dot operator (.) or the arrow member selection operator (->) then the name of the member (variable or function).
Recall that an object is an instantiated instance of a class. Any variables declared inside a member function are local to that function in the same way as any other function implementation in C++.

STATIC MEMEBERS
Also note that the way you call a class member will differ depending on the type of class member.
For example, for accessing static members, you do not use an instance name but rather the class name as in Math::Sum() as opposed to Math myMath; and then myMath.Sum().

AVOIDS NAME CONFLICT
Class scope permits the creation of class level functions and variables that will not conflict with functions or variables of the same name in a different class.
If we had two different class files such those shown below, the application knows which Speak() function to call based on the classes instance name.

    #include "stdafx.h"
    #include <iostream>
    #include "Person.h"

    01 using namespace std;
    02
    03 int main()
    04 {
    05
    06         Person person;
    07         Dog dog;
    08
    09         person.SayHello();
    10         dog.SayHello();
    11
    12         return 0;
    }

Assume that we have two classes called Dog and Person and that the Dog's SayHello() function will output "Woof" and the Person's SayHello() function outputs "Hello".
When you call person.SayHello(), the compiler knows which SayHello function to call because it is associated with the person object which is an instance of the Person class.
Therefore, that SayHello() function will be executed.

By way of example of how to call functions using the different operators, let's consider the Person class that has been used in the Constructors topic, which is recreated here.

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
        firstName = fName;
        lastName = lName;
    }

    Person::Person(std::string fName, std::string lName, int age)
    {
        firstName = fName;
        lastName = lName;

        age = age;
    }


    Person::~Person()
    {
    }

    void Person::SayHello
    {
        std::cout << "Hello" << std::endl;
    }

As we look at the Person.h and Person.cpp files, we notice that we have three private member variables, three public constructors, and one public method named SayHello().
To demonstrate the scope of member variables in a class we have also created the following main.cpp file.

    #include "stdafx.h"
    #include <iostream>
    #include "Person.h"

    01 using namespace std;
    02
    03 int main()
    04 {
    05
    06 // create a Person instance using default constructor
    07 Person *pOne = new Person();
    08
    09 // Create a Person instance using 2 argument constructor
    10 Person *pTwo = new Person("Tom", "Thumb");
    11
    12 // Create a Person instance using 3 argument constructor
    13 Person *pThree = new Person("Tom", "Thumb", 15);
    14
    15 Person p;
    16
    17 Person &pRef = p;
    18
    19 p.SayHello();
    20
    21 // pointer method of calling a member function
    22 pOne->SayHello();
    23
    24 // reference method of calling a member function
    25 pRef.SayHello();
    26
    27 return 0;
    }

In this code that makes use of the Person class, we see different ways of accessing the members of the Person class using instantiated objects.

On line 07, we dynamically allocate memory for a new Person object called pOne by using a pointer and the new keyword.
We do the same with two other pointers on lines 10 and 13.
The differences are that we are calling different constructors for each one.
pOne uses the default constructor, pTwo uses the 2 argument constructor while pThree uses the 3 argument constructor.
Constructors have class scope as well as they are declared within the class file.

On line 15, we create a new Person object called p without using a pointer or the new keyword.
The way that we declare our objects is important for determining how we call the member functions or access the public member variables as shown in this code sample.
On line 17 we declare a new reference variable that is a reference to the Person object we called p.
We call the SayHello() member function on p by using the dot operator on line 19 and that works.
We also call the SayHello function on line 25 using the dot operator and that works as well because we set pRef as a reference to p.

Note on line 22 however that in order to call the SayHello() function from the dynamically allocated Person object called pOne,
we had to use the member selection operator (->) to gain access to the SayHello() function.

For more information , you can see:
C and C++ with Visual Studio: https://aka.ms/edx-dev210.2x-vs02
