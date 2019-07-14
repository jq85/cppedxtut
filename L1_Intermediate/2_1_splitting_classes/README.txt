https://courses.edx.org/courses/course-v1:Microsoft+DEV210.2x+3T2018/course/

# Introduction to Splitting Class Files
=======================================

If an aspect of object-oriented programming is encapsulation, then why would we split our classes into separate files?
Why not keep it all in one if we wish to "encapsulate" all there is about the class?

Recall that a part of encapsulation is also data hiding.
Think about your car for a bit as we use it in an analogous way. A car is a complex device that contains many different components.
You are able to operate your car without the need to understand the complexities of the internal combustion engine or the radio electronics.
You don't need that knowledge to be able to effectively operate the car.

Likewise, a programmer using your class files does not need to know how you have implemented your methods to achieve the functionality.
In fact, perhaps you have a proprietary algorithm for a spell checker that is really fast and you don't want anybody to know how it works.
Users of that class also don't need to know how you implemented the spellchecker.
They only need to know how to make use of it.
"How to make us of it" comes in the form of the methods and their signatures.

As long as a user knows how to call your methods and what to expect as a return value, if any, they can use your class in their application.

METHOD'S SIGNATURES
In the car analogy, the owner's manual is analogous to the method signatures.
It specifies what you can do to operate the car and how to interact with the car's "interface".
In the separation of class files, the header file (.h file), is analogous to the car's owner's manual.
It specifies what "interface" elements are available (methods), providing information on how to use them.
There are no implementation details in the header file just as there are no implementation details on the internal workings of your car's engine, in the owner's manual.



# HEADER FILES
==============
The header file contains the function prototypes.
In C++, your code will often contain multiple class files.
As a review, recall that class files allow you to model real-world objects in your code, and they also provide a container for functionality and behavior of coding structures.

C++ applications typically consist of multiple files. Each of these files in your application may use any or all of the class files that you define in your application.
If this is the case, that class file definition must be the same in each and every file that uses it.
In order to avoid the duplication of code, C++ uses the concept of a header file and the #include preprocessor directive.

In C++, the common practice is to create your classes as two separate files:
  - The header file, with a .h extension on the filename, is used to contain the declarations found in the class file.
    Declarations include function prototypes and class constructors typically.
  - The actual implementation of the code that performs the processing,
    exists in the implementation file that has the .cpp or .c filename extension.

To illustrate an example, let's go back to one of the examples found in the Introduction to C++ course on edX by Microsoft.
In Module 4 we created functions that represented some common mathematical operations to calculate the power of a base raised to an exponent,
calculate the sine of an angle, and finally one to calculate the average of values in an array.
For this example, we will start to focus on building our own math library.

In C++, there is an existing library called cmath.
This library contains many common mathematical functions and we can simply make use of cmath rather than create our own library,
but the exercise of doing so will serve a couple of purposes in this course.
First, it will allow you to learn how to create class files with header files.
Next, you will learn how to deal with namespaces, which are covered later in this module,
and finally, the culmination of the math functions that you will build will help to serve as a project for this course.

This sample code will provide a starter for you by demonstrating the use of header and implementation files for
a class called Math with a function for calculating the value of a base raised to an exponent. We'll call this function pow.

Math.h

    // Math.h
    // Header file for the Math class

    #pragma once

    // Math class definition
    static class Math
    {
        public:

        // given base and exponent, calculate value
        static int Math::pow(int base, int exp);

    };


Let's evaluate the code listings one at a time. In the first section, Math.h, we see the header file for our Math class.

PRAGMA
Outside of the comments we see a line that indicates #pragma once.
This is a preprocessor directive that tells the compiler to only include this header once, regardless of how many times it has been imported in the program.

STATIC CLASS
Next we see the class definition, static class Math.
The static keyword needs a little explanation so let's get that out of the way first.
When we declare a class as static, it is an indicator that we do not have to instantiate the class to use it in our program.

For example, if Math were not static, before we could use it in our program, we would need to create an instance of it as shown here:
    Math math = new Math();
    math.pow(2, 8);

For the Math class that we are creating in this course,
we will consider it to be a utility class and therefore we want it to be static
so we don't have to create an instance each time we want to use functionality in that class.

PUBLIC
Next, our class definition continues with the opening curly brace and then the keyword public:
Anything after the public: keyword is considered to be of public visibility.
That is, it can be called from other classes directly.

PUBLIC STATIC METHOD
After public: we declare our function for generating the power of a base raised to an exponent.
Note that this method is also using the static designation.
In order to call the function from a static class, the function must also be static.

Note that the function contains no implementation details however. We simply indicate the data types of the parameters that we expect to use with this function.
As a matter of fact, we don't even have to use parameter names in this declaration at all, simply using static int Math::pow(int, int);
is sufficient as we only need to indicate the data types that are expected by the function.

The last key piece to note about this declaration of the Math class is that we end it with a semicolon after the closing curly brace.
Most new programmers have a tendency to forget this.  Microsoft Visual Studio automatically adds the semicolon for you and many newer IDEs may also do the same.

For more information , you can see:
C and C++ with Visual Studio: https://aka.ms/edx-dev210.2x-vs02



# IMPLEMENTATION FILES
======================
Let's now look at the implementation file, the one with the .cpp extension and the file that contains the actual functionality.

Math.cpp

    #include "stdafx.h"
    #include "Math.h"

    int Math::pow(int base, int exp)
    {
        int result = 1;

        for (int i = 0; i < exp; i++)
        {
            result = result * base;
        }

        return result;
    }

MathTest.cpp

    // MathTest.cpp : Defines the entry point for the console application.
    //

    #include "stdafx.h"
    #include "Math.h"
    #include <iostream>

    using namespace std;

    int main()
    {
        int result = Math::pow(2, 10);

        cout << result << endl;

        return 0;
    }

Let's evaluate the code listings one at a time.
In the first section we saw Math.h, the header file for our Math class.  In this section, we discuss the Math.cpp file. This is the implementation file for the Math class.

STADFX.H
We open the class file with two #include statements.
One includes the stdafx header file and the second brings in the Math header file.
The stdafx.h file is the precompiled header directive that is used in Visual Studio but some other compilers also make use of it.
Next, we include Math.h because the compiler needs to know what functions are part of this class.
Recall the discussion about function prototypes. These now exist in the header file and not in the .cpp file.

SCOPE RESOLUTION OPERATOR "::"
The rest of the class contains the implementation details for calculating the power function. The function name looks a little different now.
Instead of just the function name, we are using Math::pow as the function name. This is using the concept of a scope resolution operator (::).
There are a couple of uses for the scope resolution operator, and it will be covered again in the discussion on namespaces but, in this instance, it is required to call static members of the class.

DRIVER PROGRAM FOR TESTING
Finally, in MathTest.cpp we see our standard main() function that we use for testing purposes.
Some refer to this as a driver program used for testing our code.
In the main() function, declare an int variable called result and assign it the value that is returned from the pow function in Math.
Note the use of the scope resolution operator again (::) and that we did not create an instance of the Math class but simply called the function directly on the class itself.
This is an example of a static class in action.

HEADER FILE
So how exactly does the header file factor into our code?
It is a concise method of describing what the class is intended to do.
In other words, it provides a look into the functions that exist in a class without concerning ourselves with the implementation details of those methods.
It also provides us with a mechanism to help reduce coding bugs by having the compiler catch omissions and misuses of the class and its components.
However, once again think about declaring a class in your applications main file, the one that includes main().
In our sample code with the Math class, if we did not include the Math.h file directive in MathTest.cpp, then MathTest will have no knowledge of Math.cpp and the compiler will generate an error.
By placing the include directive in MathTest.cpp, the compiler will actually make a copy of the contents of Math.h inside MathTest.cpp, which will mean that the function declarations will be included,
and the compiler will understand the Math class.
