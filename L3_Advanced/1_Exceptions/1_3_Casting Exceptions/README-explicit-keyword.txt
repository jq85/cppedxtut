# EXPLICIT KEYWORD
==================
The explicit keyword is used to specify a conversion,
cannot be used for implicit conversions,
and is mainly used to declare a conversion constructor can only be used for explicit conversions.
In c++11 it can also be used to declare a conversion function.
Consider the following example.


  #include <iostream>

  class explicitConversion {

  public:

      explicit explicitConversion(float floatin) : convertValue{ floatin } {};

      void printValue(const explicitConversion expC);

      float convertValue;
  };

  void explicitConversion::printValue(const explicitConversion expC) {
      std::cout << "The value of convertValue is : " << expC.convertValue << std::endl;
  }

  class Conversion {

  public:

      Conversion(float floatin) : convertValue{ floatin } {};

      void printValue(const Conversion expC);

      float convertValue;
  };

  void Conversion::printValue(const Conversion expC) {
      std::cout << "The value of convertValue is : " << expC.convertValue << std::endl;
  }



  int main(){
      explicitConversion mycc(100.01);
      Conversion myc(64.06);

      mycc.printValue(mycc);      //No conversion
      double myccdouble(53.53);
      mycc.printValue((explicitConversion)myccdouble);      //Explicit conversion of double to float.

      //Conversion would be illegal with explicit hence wont work with mycc object of type explicitConversion.
      double mycdouble(23.23);
      myc.printValue(mycdouble); //Implicit conversion double to float.

      return 0;
  }


In the above example we create two classes on defined with an explicit constructor and the other without.
In the main method we initialize an instance of each class,
the first class instance of type explicitConversion we then use to show an explicit cast conversion of the double myccdouble to a float and print the value 53.53.
The next object of type Conversion we use to do an implicit cast of the double mycdouble to a float and print the value 23.23.
