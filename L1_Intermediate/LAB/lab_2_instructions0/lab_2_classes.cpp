#include "Course.h"
#include "Teacher.h"
#include "Student.h"
#include <iostream>

using namespace std;
// using namespace C;

int main()
{
  //1. Instantiate three Student objects called Student1, Student2, and Student3, provide values for the member variables.
  S::Student s1("Jan", "Tomusko", 29);
  S::Student s2("Ladislav", "Kozel", 41);
  S::Student *s3 = new S::Student();
  s3->SetFirstName("Jose");
  s3->SetLastName("Quintans");
  s3->SetAge(32);

  //2. Instantiate a Course object called Intermediate C++.
  Course *intermediate_cpp = new Course();

  //3. Add your three students to this Course object.
  intermediate_cpp->addStudent(s1);
  intermediate_cpp->addStudent(s2);
  intermediate_cpp->addStudent(*s3);

  //4. Instantiate at least one Teacher object.
  T::Teacher *t1 = new T::Teacher();

  //5. Add that Teacher object to your Course object
  intermediate_cpp->addTeacher(*t1);

  //6. Using cout statements where appropriate, follow these instructions:
  //6.1. Output the name of the course
  cout << intermediate_cpp->GetName() << endl;
  //6.2. Call the GradeStudent() method on the Teacher object
  t1->GradeStudent();
  //6.3. Leave your application open and answer the Lab assessment questions

  return 0;
}
