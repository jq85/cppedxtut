https://courses.edx.org/courses/course-v1:Microsoft+DEV210.2x+3T2018/course/

POINTER:
  > OPERATOR
  > ADDRESS
  > DEREFERENCE

  int num = 3;        // if &num = 0x00017
  int *pNum = &num;   // then pNum == 0x00017, i.e. it points to the address of num.
                      // though the address of pNum is different.
  int *pNum = 33;     // Now num = 33

#INTRODUCING POINTERS
=====================

A variable actually references a location in the computer's memory.  The memory location is what gives num an identity.  During an execution of the application code, while num is in scope, it will have one memory address for the entirety of its scope. Most objects in C++ have an identity, which means that they have a unique memory address during their lifetime (scope).

A pointer is simply a variable that holds the memory address of an object in C++.  To use pointers, you create a pointer variable.  As an example, if we want to, we can create a variable to point to our num variable's address in memory by using the following line of code:
    int* pNum = &num;
In this line of code, int* is referred to as a pointer to an int.
The & symbol, in this instance, is known as the  address-of operator and it allows us to get at the memory address for the num variable.

Depending on the documentation you read, you may also find the * used in this manner:

    int *pNum;

In this case, the author of the text is trying to show that pNum is the actual pointer.  Regardless, the concept is the same.  pNum is a pointer an int.
Because we declared it as an int pointer, or a pointer to an int, the compiler knows to request memory large enough to store an integer value.

NOTE: A word of caution when using pointers.  You should always initialize a pointer variable to NULL, nullptr, 0, or with a memory address.   Leaving a pointer variable uninitialized is an error that can result in difficult to find bugs and create security issues for your code.

    int *pNum;  // not recommended

    cout << pNum << endl;
Referring to the preceding code, some compilers will not compile the code and will issue a warning or raise an error because of the pointer not being initialized.  For compilers that do not catch this error, you could see a memory address output to the console but you will have no idea what data resides at that memory address.

One final note, when declaring a pointer, ensure that the variable you will be pointing to is the same data type as the pointer you are declaring.  This is important because of the difference in the number of bytes stored in the various data types.
For more information , you can see:
C and C++ with Visual Studio: https://aka.ms/edx-dev210.2x-vs02



#OVERLOADING '*'
#THE DEREFERENCE OPERATOR
==========================

The Dereference Operator
 Bookmark this page
This operator is another source of confusion for those who are new to pointers.
The reason is because we are "overloading" the use of the * symbol.
It is used as the pointer symbol and also as the dereference symbol.
So what is a dereference?  Consider the following code sample.

    int num = 3;            // a simple variable holding the value 3
    int *pNum = &num;        // a pointer holding the address of num
    cout << pNum << endl;    // output the memory address of num
    cout << *pNum << endl;    // output the value 3

On the last line outputs the value 3.  Why?  Here is where the power and the danger of pointers starts to become apparent.

Using the dereference operator, you can gain direct access to the underlying value in the variable num.
Using the dereference operator, you can change the underlying value of num, indirectly.
The two last cout lines demonstrate that the value of num and *pNum are precisely the same value. You might be thinking at this point that we could simply have changed the value of num directly and you would be correct. But hold that thought for a moment and  we'll revisit the importance of this later in the lesson when we discuss the purpose of pointers and their uses.



#Why Pointers?
================

PERFORMANCE
One reason for using pointers is application performance.
In our simple examples thus far, the amount of data that we have passed into functions has been small.
But if we were using large data structures, as class files can sometimes be,
or if need to perform repetitive operations on lookup tables,
then it is far more efficient to pass a pointer,
which is just the memory address, than it is to pass the entire data structure.

SAVE MEMORY
As you saw in the code example that passed a variable by reference,
pointers can also be used to modify the value in the variable passed in.
Once again, the pointer provides a direct link to the underlying value of the variable allowing you to change the value without the overhead of copying the value into the function.

DYNAMIC MEMORY ALLOCATION
Pointers also allow you to dynamically allocate memory in your application.  You may run across a requirement for this when creating arrays and objects in your C++ code.  Dynamically allocating means that you do not need to know the size of memory that will be needed for an object at compile time but rather that the size will be allocated during runtime of the application.

DIRECT ACCESS
However, it we are dealing with objects, it can be more complicated because we might be
declaring objects dynamically as the application runs and at the time you are writing the code,
you may not have all variable names available to you.
As a result, we can make use of the dereference operator.

    int contents = *pNum;

In this line of code, we are assigning the variable contents, the value
that is located in the memory address pointed to by pNum.
This is sometimes considered direct access.
It is also the cause of confusion in C and C++ programs and can result in unintentional
assignment of values in memory.
So, how do we know whether we are using the asterisk as a pointer operator or a dereference
operator?
  > left of assignment means pointer.
  > the right side of assignment, which makes it a dereference operator.
