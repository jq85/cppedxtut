https://courses.edx.org/courses/course-v1:Microsoft+DEV210.2x+3T2018/course/

EMBEDDED.com: References vs. Pointers
https://www.embedded.com/electronics-blogs/programming-pointers/4023307/References-vs-Pointers

#OVERLOADING '&'
#BINDING: #INTRODUCING REFERENCE TYPES
======================================
C++ includes a type known as a reference.  A reference type is simply an alias for another type.
It "refers to" or "references" another type in your code.
A reference type overloads the use of the & operator.
So far you have seen the & operator used to represent the address-of operator for obtaining the address of a variable.
References also use this operator to denote a reference to another variable.

You declare a reference type using a syntax similar to declaring a pointer variable.  That is, you declare the data type of the C++ variable or object that will be referred to, then you use the & character followed immediately by the reference type name.  Finally, it's important to note that when declaring a reference, you must assign it at that time.  It behaves similar to a constant in this sense.  An example demonstrates the declaration.

    //create an integer variable called num and assign it a value of 3.
    int num = 3;
    //declare a reference called refNum.
    int &refNum = num;
    //The & character tells us this is a reference value. Note that we immediately assign it to the num variable.
    //This binds refNum to num.
    //This reference cannot   be reassigned later in program code.
    int &refNum2;
    //
    cout << refNum << endl;



# Passing Reference Types
=========================
What is the side-effect of passing a reference type into a function?
NO     You have to know the data type before passing a reference type
YES    Modifying the reference in the function modifies the value in memory correct
NO    Modifying the reference in the function only modifies a copy of the value
NO    You must use the ref keyword in the function prototype



# Pointer Variables
====================
Why must you provide a data type for a pointer variable even though pointer variables only store memory addresses?
YES    The complier needs to know how much to request for any value that will be stored in that memory location
NO     The compiler will create a temporary value of that type and store it in the memory location to prevent it being overwritten
NO     It isn't necessary
NO     It let's other programmers know what data to store in that pointer
