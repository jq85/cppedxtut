# DEFINING TRAIT CLASSES
========================

Normally when we create generic code we want to create something that will work for many different types, sometimes however this is not good enough.
For example suppose we could write a type specific implementation of a function that takes advantage of the machines hardware to compute something much faster than generic c++ code is able to.
Lets consider a small example, we will create some classes and give each class a trait typeid which we can access and a conversion function from our type to the standard c++ type;
First of all we define a generic template type


  template<class T> struct my_traits;
  Then we specialise this for our types long in and long double like so.

  template<>
  struct my_traits<int> {
  	enum { TypeId = MYNATIVE_INTEGER};
  	typedef mynative_integer MyNativeType;
  	static void Convert(MyNativeType from, int& to){
  		cout << "MyNativeIntegerType Convert \n";
  		to = static_cast<int>(from);
  	}
  };

  template<>
  struct my_traits<double> {
  	enum { TypeId = MYNATIVE_DOUBLE };
  	typedef mynative_double MyNativeType;
  	static void Convert(MyNativeType from, double& to) {
  		cout << "MyNativeDoubleType Convert \n";
  		to = static_cast<double>(from);
  	}
  };
  The we will use these types in the main function to print our their typeid and calll the conversion function.

  int main() {

  	cout << "my_traits<int> typeid is " << my_traits<int>::TypeId << "\n";

  	mynative_integer mni = 6;
  	int intresult;	my_traits<int>::Convert(mni,intresult);

  	cout << "\n";

  	cout << "my_traits<double> typeid is " << my_traits<double>::TypeId << "\n";
  	mynative_double mnd = 6.6666;
  	double doubleresult;
  	my_traits<double>::Convert(mnd, doubleresult);

  	cout << "\n";

  	return 0;
  }



So we have seen how we can define our own type trait information using template specialization.
In the STL numerical_limts template you will find trait information about the fundamental c++ arithmetic types, including the max and min values a type can hold.
C++11 has introduced the type_traits template classes such as is_integral test for integral types that can be used in template metaprogramming.
