# SPECIFYING DEFAULT TEMPLATE PARAMETERS
=======================================

Default template arguments were introduced in C++11 and can have value or type defaults.
For multiple default arguments all arguments after the first default argument must have defaults.
You cannot have float default arguments and you should get a compiler error if you try depending on the compiler.
Consider this simple example.

  #include <iostream>

  using namespace std;

  template<typename A=int, typename B=double , int anint = 5>
  void printParams(A ain,B bin) {
  	cout << "Arguments are A is type " << typeid(ain).name() << " with value " << ain << " B type is " << typeid(bin).name() << " with value " << bin << " anint is " << anint << endl;
  }

  template<class C, typename A = int, typename B = double, int anint = 5 >
  class myClass {
  public:
  	myClass(C myc, A ain, B adouble) {
  		cout << "myClass constructor parameters myc is type " << typeid(myc).name() << " with value " << myc << " anint is " << ain << " adouble is " << adouble << " anint is " << anint << endl;
  	}


  };

  int main() {

  	printParams(99, 33.333);

  	cout << "\n";

  	int testint = 78;
  	myClass<int>(testint,6,6.66);

  	cout << "\n";

  	return 0;
  }
At the beginning I define a template function printParams which has three default parameters, the first one is type defaulted to int, the second type defaulted to double and the last one is assigned the value 5 as default. The function prints out the types and values of the parameters. Then I define a template class called myClass which has four default parameters and a constructor that prints out the type and values of the parameters.
From this you can see how to define default template arguments, and assign them types or values.
