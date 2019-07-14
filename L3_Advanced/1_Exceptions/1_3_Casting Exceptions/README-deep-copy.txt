# COPY CONSTRUCTORS AND ASSIGNMENTS
===================================


Copy Constructors and assignment
A copy constructor is used to make a copy of an existing object instance.
There are 4 possible function signatures for a copy constructor.


  someClass( const someClass& other );
  someClass( someClass& other );
  someClass( volatile const someClass& other );
  someClass( volatile someClass& other );


If you do not declare a copy constructor the compiler will generate one for you automatically.
The compiler generated one is only capable of a shallow member copy,
If you have pointers to memory locations in your class you will need to declare a copy constructor
so you can do a deep copy on the memory location to the new object.
The reason for copying memory pointed to by a pointer is that the object which owns the point is responsible for destroying it.
If you only copy the pointer then you might have two objects pointing to the same memory location,
and one of them could delete it and then the other object will throw a null pointer exception.
As an example consider the code below.



  #include <string>
  #include <iostream>

  using namespace std;

  class MyDeepClass {

  public:


      //Constructor
      MyDeepClass(int x, char cc, std::string ss, int* intp);

      //Deep copy constructor
      MyDeepClass(const MyDeepClass &other);

      //Print function.
      void MyDeepClassPrint();

  private:
      int x;
      char c;
      std::string s;
      int* intptr;
  };


  void MyDeepClass::MyDeepClassPrint() {
      cout << x << " " << c << " " << s << " " << *intptr;
  }

  MyDeepClass::MyDeepClass(int xx, char cc, std::string ss, int* intp) :
      x(xx), c(cc), s(ss), intptr(intp) {
      cout << "MyDeepClass constructor called " << endl;
  }

  MyDeepClass::MyDeepClass(const MyDeepClass &other) :
      x(other.x), c(other.c), s(other.s){
      //copy intptr memory.
      cout << "MyDeepClass copy constructor called " << endl;
      intptr = new int(*other.intptr);
  }


  class MyShallowClass {

  public:
      MyShallowClass(int xx, char cc, std::string ss):x(xx),c(cc),s(ss) {
          cout << "MyShallowClass constructor called." << endl;
      }

      void MyShallowClassPrint() {
          cout << x << " " << c << " " << s;
      }

  private:
      int x;
      char c;
      std::string s;
  };



  int main() {

      int myint = 67;
      int myintx = 55;
      std::string mystring("Hello Deep World");

      int myShallowIntx = 1111;
      std::string myShallowString("Hello Shallow World");

      MyDeepClass mdc(myintx,'S',mystring,&myint);

      MyDeepClass mdcCopy(mdc);

      MyShallowClass msc(myShallowIntx,'Z',myShallowString);

      MyShallowClass mscCopy(msc);

      cout << "MyDeepClass mdc member values are ";
      mdc.MyDeepClassPrint();
      cout << endl;

      cout << "MyDeepClass mdcCopy member values are ";
      mdcCopy.MyDeepClassPrint();
      cout << endl;

      cout << "MyShallowClass msc member values are ";
      msc.MyShallowClassPrint();
      cout << endl;

      cout << "MyShallowClass mscCopy member values are ";
      mscCopy.MyShallowClassPrint();
      cout << endl;

      return 0;
  }



So from the output of the code we can see that the MyDeepClass copy constructor is called when we create the mdcCopy object,
and the MyShallowClass compiler generated copy constructor is called for the creation of the mscCopy object as we would expect.

Now we will add an assignment operator to the above code since the MyDeepClass contains a pointer it is a good example
because if we don't check for self assignment in the operator then we could get undefined behaviour when deleting the memory pointed to by the pointer.



  #include <string>
  #include <iostream>

  using namespace std;

  class MyDeepClass {

  public:


      //Constructor
      MyDeepClass(int x, char cc, std::string ss, int* intp);

      //Deep copy constructor
      MyDeepClass(const MyDeepClass &other);

      //Assignment operator
      MyDeepClass& operator = (const MyDeepClass &rhs);

      //Print function.
      void MyDeepClassPrint();

  private:
      int x;
      char c;
      std::string s;
      int* intptr;
  };


  void MyDeepClass::MyDeepClassPrint() {
      cout << x << " " << c << " " << s << " " << *intptr;
  }

  MyDeepClass::MyDeepClass(int xx, char cc, std::string ss, int* intp) :
      x(xx), c(cc), s(ss), intptr(intp) {
      cout << "MyDeepClass constructor called " << endl;
  }

  MyDeepClass::MyDeepClass(const MyDeepClass &other) :
      x(other.x), c(other.c), s(other.s){
      //copy intptr memory.
      cout << "MyDeepClass copy constructor called " << endl;
      delete intptr;
      intptr = new int(*other.intptr);
  }

  MyDeepClass& MyDeepClass::operator = (const MyDeepClass &rhs)
  {
      cout << "MyDeepClass operator= called." << endl;
      //Check for self assignment.
      if (this != &rhs)
      {
          x = rhs.x;
          c = rhs.c;
          s = rhs.s;
          delete intptr;
          intptr = new int(*rhs.intptr);
      }
      return *this;
  }


  class MyShallowClass {

  public:
      MyShallowClass(int xx, char cc, std::string ss):x(xx),c(cc),s(ss) {
          cout << "MyShallowClass constructor called." << endl;
      }

      void MyShallowClassPrint() {
          cout << x << " " << c << " " << s;
      }

  private:
      int x;
      char c;
      std::string s;
  };



  int main() {

      int* myint = new int(67);
      int myintx = 55;
      std::string mystring("Hello Deep World");

      int myShallowIntx = 1111;
      std::string myShallowString("Hello Shallow World");

      MyDeepClass mdc(myintx,'S',mystring,myint);  //Declared Constructor

      MyDeepClass mdcCopy(mdc);  //User defined copy constructor

      MyShallowClass msc(myShallowIntx,'Z',myShallowString); //Declared constructor

      MyShallowClass mscCopy(msc);  //Compiler generated copy constructor

      cout << "MyDeepClass mdc member values are ";
      mdc.MyDeepClassPrint();
      cout << endl;

      cout << "MyDeepClass mdcCopy member values are ";
      mdcCopy.MyDeepClassPrint();
      cout << endl;

      cout << "MyShallowClass msc member values are ";
      msc.MyShallowClassPrint();
      cout << endl;

      cout << "MyShallowClass mscCopy member values are ";
      mscCopy.MyShallowClassPrint();
      cout << endl;

      //Create LHS object.
      int* myassignint = new int(1111);
      int myassignintx = 9999;
      std::string myassignstring("Assignment operator");
      MyDeepClass mdcAssign(myassignintx, 'V', myassignstring, myassignint);

      cout << "MyDeepClass mdcAssign member values before assignment are ";
      mdcAssign.MyDeepClassPrint();
      cout << endl;

      //Call assignment operator.
      mdcAssign = mdc;

      cout << "MyDeepClass mdcAssign member values after assignment are ";
      mdcAssign.MyDeepClassPrint();
      cout << endl;

      return 0;
  }



Now we have added the operator function MyDeepClass::operator = and in there we print to standard output to show the function has been called and then we do a self assignment check. This check is so we don't try to assign the memory pointed to by intptr to its self as we delete the pointer first this would cause undefined behaviour. We then copy the int x,char c, and string s members from the right had side object and then delete the memory pointed to by intptr and assign new memory with the value from the right hand side intptr.
