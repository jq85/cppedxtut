https://courses.edx.org/courses/course-v1:Microsoft+DEV210.2x+3T2018/course/

# ENCAPSULATION
===============
Enter the C++ access modifier that allows you to encapsulate data inside a C++ class, requiring access by other means:
    > "private".

When we consider the term encapsulation we should be clear on the context in which we are using it.

INCLUSION OF DATA AND FUNCT IN ONE PACKAGE
We can say that encapsulation is the programming language aspect that permits the inclusion of data and functionality into a single package.
In this definition, inclusion means to take all of the data (member variables) and functionality that acts on that data (member functions) and enclose it within the definition of a class file.

DATA HIDING AND RESTRICTION
The second definition is considered data hiding or data restriction.
As an example to help explain this definition, consider the case of our Person class used in previous topics.
We may want to ensure that a user of the Person class cannot set the first name, last name, or age member variables directly.
In our sample code, we have declared these member variables to be private, which means direct access is not possible.
The only way, in the current code sample, to set these variables' values is to use the constructor.

BEST PRACTICE
PUBLIC GETTERS & SETTERS: GIVE ACCESS BUT RETAIN CONTROL THROUGH LOGIC (e.g. for data validation).
A best practice is to also provide public functions that allow users of the class to change these values but indirectly.
That is to say, they can only modify the values through the use of a public function.
Inside that function, you, as the developer, control how data passed in from the user is handled.
For example, you might want to validate the data passed in for the age variable to ensure it is a valid age for the intended purpose.
In other words, if a user attempts to pass in a negative value or a character value for age, your public method could check for these instances and handle the situation appropriately.
You might send an error message to the user or you could trim blank spaces, etc.

The important part of encapsulation from the second definition perspective is that users of your class have no insight into how you set the values or validate the information.
It's indicative of the way in which you require absolutely no knowledge of the internal combustion engine in order to turn the ignition key and start it.

To implement encapsulation in our Person class, we could add the following code to the Person class to facilitate setting and retrieving the values for the member variables.

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

        int count;
        Person();

        Person(std::string fName, std::string lName);

        Person(std::string fName, std::string lName, int age);

        ~Person();

        void SetFirstName(std::string fName);
        std::string GetFirstName();

        void SetLastName(std::string lName);
        std::string GetLastName();

        void SetAge(int age);
        int GetAge();

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

    void Person::SetFirstName(std::string fName)
    {
        this->firstName = fName;
    }

    std::string Person::GetFirstName()
    {
        return this->firstName;
    }

    void Person::SetLastName(std::string lName)
    {
        this->lastName = lName;
    }

    std::string Person::GetLastName()
    {
        return this->lastName;
    }

    void Person::SetAge(int age)
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

    int Person::GetAge()
    {
        return this->age;
    }

    void Person::SayHello()
    {
        std::cout << "Hello" << std::endl;
    }

**Test Program**

    int main()
    {
        Person p;

        p.SetFirstName("Gerry");
        std::cout << p.GetFirstName() << std::endl;

        // this line will output an invalid age message due to the
        // validation check in the SetAge() function
        p.SetAge(-5);

        // this line will not work because firstName is private
        p.firstName = "Gerry";

        return 0;
    }


In our revised code, we have added some functions to set and get the member variables.
Outside of the constructors, this is the only way to set these values and now we actually have functions that will return these values if we need them in our program code.

In our sample test program code, we declare a Person variable called p.
We then use the dot notation to call the SetFirstName() function and also call the GetFirstName() function to output the value to the console window.
The SetFirstName() does nothing special other than to set the firstName member variable to the value passed into the function call.

Next we called the p.SetAge() function and passed in a value of -5.
This is, of course, an invalid age value.  In our SetAge() function, we have simple logic that just checks to see if the value passed in is greater than 0.
If it is, the assignment is made but if not, a message is sent back to the user of the application.
The encapsulation aspect to this is simple that the user has no idea what validation code we have placed in SetAge(),
nor do they know how we are checking the age, setting the age, or outputting the message.   They simply see the results of the function call.

Finally, in the last part of the code we attempt to set the firstName member variable of the p object directly.
This will generate a compiler error when you attempt to compile the program code.
Depending on your compiler, the error message may differ but Visual Studio 2015 will give the error '=': function as left operand.
In fact, the Intellisense feature in Visual Studio will not even list private member variables for auto completion of code
which should be a clear indicator to the developer that the line of code contains an error.

For more information , you can see:
Visual Studio: https://aka.ms/edx-dev210.2x-vs01
