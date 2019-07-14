# Template Functions

Template functions are a c++ language feature for code reuse. By defining a template function, it allows us to use the function for multiple types without changing the function for specific types. This is also known as “Generic Programming” as we create a generic function and we can apply it to many different types. For example, consider a user defined function called printTypeName(pType) that prints the type name of the parameter pType to standard output. The c++ compiler expects the pType type to be declared at compile time, without using templates we would have to overload this function with the various types available in the c++ language. Consider the following code

void printTypeName(int x) {
	cout << typeid(x).name() << endl;
}
If we wanted to use this printTypeName function with floats we would have to overload the function like so with the type float.

void printTypeName(float x) {
	cout << typeid(x).name() << endl;
}
And if we wanted to use printTypeName with Boolean's we would overload as

void printTypeName(bool x) {
	cout << typeid(x).name() << endl;
}
With template programming we wouldn't have to provide overloaded functions we could just declare one printTypeName function.

template<typename T>
void printTypeName(T x) {
	cout << typeid(x).name() << endl;
}
This way we could use the printTypeName function with int's, floats and Boolean's, in fact any c++ type or user defined type.

The first line template<typename T> tells the compiler this is a template angle brackets contain the type or types. typename T specifies the type that will be varied, known as parametrizing type. You can also write this line as template<class T> which means the same thing to the compiler however I prefer to us the class word when templating a class and typename for all other types.

We can call the template function printTypeName a couple of ways. Firstly we can call it by explicitly specifying the type like so

int myint = 5;
printTypeName<int>(myint);

double mydouble = 99.9;
printTypeName<double>(mydouble);
However with template function the compiler can perform type deduction to determine the parametrizing types when we don't provide them, hence we can also call printTypeName like so

int myint = 5;
printTypeName<>(myint);

double mydouble = 99.9;
printTypeName(mydouble);
The first call with empty angle brackets tells the compiler that we are calling a template function and the second call leaves it up to the compiler to infer. The problem is with the second call you cannot have any other functions by the same name as function templates cannot be overloaded but as we will see they can be specialized. The above code is shown in the following code (see template_1.cpp)
