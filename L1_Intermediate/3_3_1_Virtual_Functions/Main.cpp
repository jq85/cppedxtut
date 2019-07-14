#include <string>
#include "Student.h"
//NOTE: It is enough to import Student.h

int main()
{
    // A base-class pointer can point to that type of object, or to any derived type of object.
    Person *p1 = new Person;
    Person *p2 = new Student;
    Person *p3 = new Student;
    Person p4;

    // A base-class reference can refer to that type of object, or to any derived type of object.
    Person &r1 = *p1;
    Person &r2 = *p2;
    Person &r3 = *p3;
    Person &r4 = p4;

    /*
    * INVOKING VIRTUAL FUNCTIONS
    */
    // Declare a pointer of type Person, which actually points to a Student object.
    Person *p = new Student;
    // Call the virtual display() function. This will call the Student display() function,
    // because that's the type of object p points to at run time.
    p->display();

    // The same effect happens when you use references:
    // Declare a reference of type Person, which actually refers to a Student object.
    Person &r = *p;
    // Call the virtual display() function. This will call the Student display() function,
    // because that's the type of object r refers to at run time.
    r.display();

    return 0;
}
