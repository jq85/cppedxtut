#include <iostream>
#include <typeinfo>

using namespace std;


template<typename T>
void printFunction(T arg) {
  cout << "printFunction arg is type " << typeid(arg).name() << " with value " << arg << endl;
}


template<>
void printFunction(int intarg) {
  cout << "printFunction specialization with int arg only called with type " << typeid(intarg).name() << " with value " << intarg << endl;
}


template<class C>
class myClass {
public:
  myClass() {
    cout << "myClass constructor called " << endl;
  }
};


template<>
class myClass<int> {
public:
  myClass() {
    cout << "myClass int specialization called. " << endl;
  }
};

/*
* This function here is a recursive template functions.
* So it accepts an integer type N, and then it will call itself with N minus 1 until it gets to zero.
* When it gets to zero, it'll execute the template specialization here only accepts zero value of integer.
* And we'll see that when zero is printed out, and then it will return up here and print the results.
* So, it will count up. So it will be one, two, three, four, 5-10, and what for N is one, two, three, four in new precedent.
*/
template<int N>
void printCountUp() {
  printCountUp<N-1>();
  cout << N << "\n";
}

/*
* This is template recursion. This is a very powerful medium and template specialization.
* This is a very powerful medium and template specialization.
* We can only do it because we can specialize this function here, including zero.
* You can use the score obviously to do factorials or Fibonacci numbers, Towers of Hanoi.
* There’s all sorts of applications for template recursion.
* And it's all done in compile time.
* So, there's no run time type penalty, time penalty, execution penalty unless it's more optimized than doing it in a fully run time, for instance.
*/
template<>
void printCountUp<0>() {
  cout << 0 << "\n";
}


/*
And then we have another specialization here.
So we are going to
print out ParamTypes for this function.
So we have a template type,
and then we have an argument
that accepts type int
The partial specialization that
we exchange one type of int,
which we did on that one.
*/
template<typename T, int size>
void printParamTypes(T myt) {
  cout << "printParamTypes types are " << typeid(myt).name() << " and size " << typeid(size).name() << " with value " << size << endl;
}

/*
And then it's the same function and everything,
and then you print out the name and the value.
Except we have the word specialization
So this is the partial specializations, if we're not
accepting the type primitive,
They were accepting the default type int size here.
Sometimes, we need to do this if you want to
create arrays of a fixed size
or if you want to create dynamic arrays,
for instance, or erase the specific type.
But here, so you might just hardcode a char array of size ‘size’
You might create an array of integers, size ‘size’.
*/
template<int size>
void printParamTypes(char c) {
  cout << "printParamTypes partial specialization types are " << typeid(c).name() << " with value " << c << " and size " << typeid(size).name() << " with value " << size << endl;
}


int main() {
  printFunction(99.9);

  cout << endl;

  printFunction(9);

  cout << endl;

  /*
  Now, we carry the class double, which once again,
  is the default implementation for class,
  and then the temporary specialization for the integer,
  we create after that.
  So we'll see the difference printed out
  here between the specialization word and the standard output in main.
  */
  myClass<double>();

  cout << endl;

  myClass<int>();

  cout << endl;

  printCountUp<5>();
}
