# SPECIALIZING TEMPLATES
========================

Normally when we write a template class or function we want to use it with many different types,
however sometimes we want to code a function or class to make use of a particular type more efficiently, this is when we use a template specialization.
To declare a template specialization we still use the template keyword and angle brackets <> but leave out the parameters like so.

  template<>

So we can create a function called printFunction which prints out its type and value like so

  template<typename T>
  void printFunction(T arg) {
  	cout << "printFunction arg is type " << typeid(arg).name() << " with value " << arg << endl;
  }

Then we can specialize this for integer values like so.

  template<>
  void printFunction(int intarg) {
  	cout << "printFunction specialization with int arg only called with type " << typeid(intarg).name() << " with value " << intarg << endl;
  }

## RECURSION
And we can do the same think with classes which you will see in the demo.
One interesting result of template specialization is it's use in recursion.
Hopefully you are already familiar with recursion and the requirement to have a base case when the recursion finishes and returns up the call stack.
This base case can be represented as a template specialization,
consider the following template function that prints out a count up of all the integer numbers from 0 to N the parameter argument.

  template<int N>
  void printCountUp() {
  	printCountUp<N-1>();
  	cout << N << "\n";
  }

  template<>
  void printCountUp<0>() {
  	 cout << 0 << "\n";
  }

It does this by using recursion in the first function by calling printCountUp<N-1>(),
which is a call to it's self decrementing the value originally passed to the function as N each time it makes the call.
All this recursion is computed at compile time hence template recursion is a useful optimisation technique if you wanted to compute factorials or fibonacci numbers
or anything that can be implemented recursively as you don't have a run time overhead.

## PARTIAL
We can also do partial template specialization where the template parameters are only partially resolved.
In the example below we declare a template function printParamTypes which has two parameters, typename T and int size.
Below that we declare a partial template specialization of printParamTypes which has one parameter int size.
Both functions print out the type and values of the parameters.

  template<typename T,int size>
  void printParamTypes(T myt) {
  	cout << "printParamTypes types are " << typeid(myt).name() << " and size " << typeid(size).name() << " with value " << size << endl;
  }


  template<int size>
  void printParamTypes(char c) {
  	cout << "printParamTypes partial specialization types are " << typeid(c).name() << " with value " << c << " and size " << typeid(size).name() << " with value " << size << endl;
  }
