https://courses.edx.org/courses/course-v1:Microsoft+DEV210.2x+3T2018/course/


# FRIEND FUNCTIONS & FRIEND CLASSES (handle-body)
=================================================
A friend function is not a member of the class, but can access all members of the class.

Friend classes are NOT mutual. For example, imagine class A defines class B as its friend.
This means class B can access all the members of class A, BUT class A cannot access the members of class B.

# FRIEND FUNCTIONS
==================

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



# FRIEND CLASSES
=================
This class represents some internal detail that you would like the shield
away from the client programmer. You don't want the client programmer to know much at
all about the Body class, and the reason for that is that you want to be able to
be able to change its implementation without necessarily
affecting the client's code.


A class can define another class as its friend. A friend class can access all the members of the first class. This is useful if you have a "binary system", that is two classes that are intimately related to each other.

A good example of friend classes is the "handle-body" idiom in C++. This idiom splits one semantic class into two related class - a "body" class that defines the private data, and a "handle" class that defines the public behavior. The body defines the handle class as a friend class, so that the handle class can access all the members (including private members) in the body class.

The following code listings show how to implement the handle-body idiom in C++ using friend classes.

**Body.h**

    class Handle;  // Forward reference of the "handle" class, so the compiler knows about it.

    class Body
    {
        friend class Handle;

    private:
        int someData;
        ...
    };

**Handle.h**

    #include "Body.h"

    class Handle
    {
    private:
        Body * body;   // The "handle" class typically maintains an internal instance of the "body" class.

    public:
        Handle();
        ~Handle();

        void someOperationOnBody();
        ...
    };

**Handle.cpp**

    #include "Handle.h"

    Handle::Handle()
    {
        body = new Body;  // Create the underlying "body" object.
    }

    Handle::~Handle()
    {
        delete body;      // Delete the underlying "body" object.
    }

    void Handle::someOperationOnBody()
    {
        someData = 42;    // Perform operations on the underlying "body" object.
    }

Client code just works with the "handle" class - the client code has no knowledge of the underlying "body" class. Consider the following example:

**Main.cpp**

    #include "Handle.h"

    int main()
    {
        Handle h;
        h.someOperationOnBody();

        return 0;
    }

For more information , you can see:
C and C++ with Visual Studio: https://aka.ms/edx-dev210.2x-vs02
