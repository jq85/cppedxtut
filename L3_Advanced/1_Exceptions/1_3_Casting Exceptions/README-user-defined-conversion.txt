# USER DEFINED CONVERSION
=========================

User defined conversion operators.
User defined conversion operators enable explicit or implicit conversion from one class type to another.



  #include <iostream>

  class myClass {

  public:
      operator int();

      explicit operator double();

  };

  myClass::operator int() {

      return 99;
  }

  myClass::operator double() {

      return 22.56;
  }

  int main() {

      myClass mc;

      int myint = mc;  //implicit conversion

      double mydouble = (double)mc;  //explicit conversion

      std::cout << " myint is " << myint << " and mydouble is " << mydouble << std::endl;

      return 0;
  }



In the above code we define a class called myClass and give it two operators.
The operator int() allows implicit conversion whilst the explicit operator double() only allows explicit conversion.
The output shows that myint gets the value 99 and mydouble gets the value 22.56, if we try to do a double implicit conversion we get the value 99.
