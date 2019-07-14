# CONTROLLING TIMING
=====================

Control timing of construction and destruction
Constructors and deconstructors can be controlled by using the new and delete operators.

  1. First you create a pointer of the type of object you want to construct
  2. and then to invoke the constructor you assign an object to the pointer using new
  3. and to invoke the deconstructor you call delete on the object.

You can also use placement new to re allocate an object and call the deconstructor explicitly.
For example:



  #include <iostream>

  using namespace std;

  class MyClass {

  public:
      MyClass() {
          cout << "MyClass constructor called." << endl;
      }

      ~MyClass() {
          cout << "MyClass deconstructor called." << endl;
      }

      std::string msg = "Hello World!!";
  private:

  };


  int main() {

      MyClass* mcptr;

      cout << "MyClass constructor for object mcptr not yet called." << endl;

      mcptr = new MyClass();

      cout << "MyClass deconstructor for object mcptr not yet called." << endl;

      delete mcptr;

      cout << "Invoke constructor using placement new" << endl;

      new(mcptr) MyClass();

      cout << "Invoke deconstructor by calling it explicitly" << endl;

      mcptr->~MyClass();

      return 0;
  }



The above code declares a pointer of type MyClass and then uses new to allocate an object to it, this invokes the constructor.
We then call delete on the pointer to invoke the deconstructor
and after this re allocate the object using the placement new syntax which again invoke the constructor
and finally we explicitly call the objects deconstructor.
The output looks like this

  MyClass constructor for object mcptr not yet called.
  MyClass constructor called.
  MyClass deconstructor for object mcptr not yet called.
  MyClass deconstructor called.
  Invoke constructor using placement new
  MyClass constructor called.
  Invoke deconstructor by calling it explicitly
  MyClass deconstructor called.
  Press any key to continue . . .

Remember that objects allocated with new do not have their deconstructors called when they move out of scope
and you need to directly call delete on the pointer or invoke the deconstructor explicitly.
