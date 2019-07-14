#include <string>
#include "Student.h"
//NOTE: It is enough to import Student.h

/*
* I try to illustrate polymorphism here
*/

void demoFunction1(Person *ptr);
void demoFunction2(Person &ref);

int main()
{

  Person *p = new Student("Jane Smith", 18, "Physics");
  /*
  * VIRTUAL
  * The compiler decides not at compile time, but at "run time" which 'display' function to call,
  * and what matters is that p is pointing to a Student object,
  * so it calls student's display function (even if p is a Person pointer)
  * all because it is a VIRTUAL function.
  */
  p->display();
  demoFunction1(p);
  demoFunction2(*p);

  delete p;

  return 0;
}


void demoFunction1(Person *ptr)
{
  ptr->display();
}

void demoFunction2(Person &ref)
{
  ref.display();
}
