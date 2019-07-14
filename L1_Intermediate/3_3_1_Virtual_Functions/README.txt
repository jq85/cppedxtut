https://courses.edx.org/courses/course-v1:Microsoft+DEV210.2x+3T2018/course/

(
  PURE VIRTUAL FUNCTION: virtual ... = 0;
  PURE VIRTUAL CLASS: contains only pure virtual functions, becoming akin to an "interface"
  pure virtual functions and pure virtual classes in C++.
  A pure virtual function is like an abstract function in other languages like Java and C#
  and a pure virtual class is like an interface in those languages.
)

# INTRODUCING VIRTUAL FUNCTIONS
===============================

FACTOR-OUT COMMON CODE
One of the reasons for using inheritance is to reuse common code across a hierarchy of related classes.
For example, if you have similar classes such as Student, Employee, and Contractor,
you can factor-out common data members and member functions into a base class such as Person.
The Student, Employee, and Contractor classes can then inherit these common members from the Person class.

OVERRIDING
When you use inheritance, you often find that the derived classes need to implement specialized versions of some member functions from the base class.
For example, the Person class might define a display() member function to display a person's name and age,
whereas the Student class might want to display the student's course as well.
This is known as "overriding".

To define overridable member functions properly in C++, you must prefix the function with the virtual keyword in the base class definition:

    class Person
    {
    private:
        std::string name;
        int age;

    public:
        virtual void display() const;        // Overrideable function.
        ...
    };

Note that you don't use the virtual keyword when you implement the function in the source file:

    void Person::display() const
    {
        std::cout << name << ", " << age << std::endl;
    }



# OVRERIDING VIRTUAL FUNCTIONS
==============================

When you define a derived class, you can optionally choose to override some or all of the virtual functions defined in the base class.
Note that you don't have to override virtual functions if you don't want to.

To override a virtual function in a derived class, re-declare the function in the derived class header file.
The function signature must match that in the base class.
You should use the virtual keyword again, to remind anyone reading your code that this is an "overrideable" function
(for example, subsequent derived classes can choose to override this function further if appropriate).

The following example shows how the Student class can declare that it overrides the display() function from its base class:

    class Student : public Person
    {
    private:
        std::string course;

    public:
         virtual void display() const;     // Override function from base class.
        ...
    };

In the source file for the derived class, implement the new version of the function for your derived class.
If you want to leverage the existing functionality of the base-class version of the function,
you can call the function using the syntax BaseClassName::FunctionName().
For example:

    void Student::display() const
    {
        // Call base-class version of display(), to display person-related info.
        Person::display();

        // Now display the student-related info.
        std::cout << course << std::endl;
    }




# VIRTUAL DESTRUCTORS
=====================

If a base class defines one or more virtual functions, then it should also define a virtual destructor.
For example, here is a virtual destructor for the Person class:

    class Person
    {
    public:
        virtual ~Person();
    };

    Person::~Person()
    {
        // Any destruction code for Person object.
    }

By defining a virtual destructor in the base class, you ensure that the correct destructor is always called when you delete an object. We discuss this subject in more detail shortly.



# THE PRINCIPLE OF SUBSTITUTABILITY
===================================

POINT TO CHILDS
In common with other object-oriented languages, C++ allows you to create base-class variables and initialize them to point to derived-class objects.
Specifically, a C++ pointer of type X can point to an X object or anything inherited from X.
Likewise a C++ reference variable of type X can refer to an X object or anything inherited from X.

Here are some examples, using the Person and Student classes:

    // A base-class pointer can point to that type of object, or to any derived type of object.
    Person * p1 = new Person;
    Person * p2 = new Student;

    // A base-class reference can refer to that type of object, or to any derived type of object.
    Person & r1 = somePersonObject;
    Person & r2 = someStudentObject;



# INVOKING VIRTUAL FUNCTIONS
============================

When you invoke a virtual function through a pointer or reference, C++ ensures the "correct" version of the function is invoked
(it's the type of the actual object being pointed to that matters, not the static type of the pointer or reference variable itself).

Consider the following example using pointers:

    // Declare a pointer of type Person, which actually points to a Student object.
    Person * p = new Student;

    // Call the virtual display() function. This will call the Student display() function,
    // because that's the type of object p points to at run time.
    p->display();

The same effect happens when you use references:

    // Declare a reference of type Person, which actually refers to a Student object.
    Person & r = someStudentObject;

    // Call the virtual display() function. This will call the Student display() function,
    // because that's the type of object r refers to at run time.
    r.display();

When you delete an object, the C++ compiler ensures a destructor is called. If you've defined the destructor as virtual, then the run-time mechanism ensures the correct destructor is called based on the type of the object (rather than the static type of the pointer):

    // Declare a pointer of type Person, which actually points to a Student object.
    Person * p = new Student;

    // Use the object.
    // ...

    // When you're ready, delete the object. If the destructor is virtual, the type of the object at run time
    // determines which destructor is called. In this case, it will be the Student destructor.
    delete p;
