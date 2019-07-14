#include <iostream>
#include "Person.h"
// #include <string>


void PassByValue(int num2);
void PassByRef(int *pNum2);
void ModifyPerson(Person *person2);


int main()
{
  int num1;
  int blah;
  // int *pNum = NULL;//WARNING
  // int *pNum = &blah;
  int *pNum = new int;

  num1 = 3;
  *pNum = 5;

  PassByValue(num1);
  std::cout << num1 << std::endl;

  PassByRef(pNum);
  std::cout << *pNum << std::endl;

  // PassByValue(pNum);//error: invalid conversion from 'int*' to 'int' [-fpermissive]

  //17. Create a pointer variable to a double, and allocate memory for it using the new keyword.
  double *pDouble = new double;
  *pDouble = 1234;
  std::cout << *pDouble << std::endl; //Use the dereference operator, get the value and output it to the console.
                                      //returns 1234
  delete pDouble;//Deallocate the memory for that variable.
  std::cout << *pDouble << std::endl; //21. Output the value stored in the memory location for that variable again.
                                      //returns 9.17547e-297

  //26. Instantiate a Person object in your main() method and assign values to the member variables.
  Person *person1 = new Person("John", "Snow", 22);
  std::cout << person1->getFistName() << " " << person1->getLastName() << " " << person1->getAge() << std::endl;

  //28. Call the ModifyPerson() function, passing in your Person object you just created.
  ModifyPerson(person1);

  //30. Back in main(), output the values stored in the Person object you created.
  //Did the name change?  It should have if you passed the object correctly to the function.
  std::cout << person1->getFistName() << " " << person1->getLastName() << " " << person1->getAge() << std::endl;
}

void PassByValue(int num2)
{
  std::cout << "PassByValue()" << std::endl;
  num2 = 23;
  std::cout << "num2 == " << num2 << std::endl;
}

/*
* Function that accepts a reference variable as an argument
*/
void PassByRef(int *pNum2)
{
  std::cout << "PassByRef()" << std::endl;
  //Modify the value of pNum, setting it to 50,  and output the value to the console.
  *pNum2 = 50;
}


/*
* 25. Create a function in your application called ModifyPerson()
* that accepts a Person object as an argument.
* NOTE: This function should be in the application area and not inside the Person class.
*/
void ModifyPerson(Person *person2)
{
  person2->setFirstName("Arthur");
}
