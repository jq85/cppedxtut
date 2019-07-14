Thinking about const from the very beginning, that's absolutely
vital to writing good classes well encapsulated code.

"get" methods in a const class should be declared with the const keyword as well.

As usual when dealing with the const keyword,
changing the location of the const key word in a C++ statement has entirely different meanings.
http://duramecho.com/ComputerInformation/WhyHowCppConst.html


Recall that the keyword const was used to indicate that a data type you use in your code is a constant and cannot have its value changed during application runtime.
Objects in your code can also make use of the const keyword to indicate that the objects are immutable.
Immutable simply means that they cannot change.


ACCESS TO CONST FUNCTIONS OR PARAMS
It says "the object has type qualifiers not compatible with member function".
But as you saw, the implementation for this function might not even be in the header file.
And there has to be a way to tell the compiler you know what


ERROR: passing xxx as 'this' argument of xxx discards qualifiers
Calling a non-const member function on const object which is not allowed because non-const member functions make NO PROMISE not to modify the object;
So the compiler is going to make a safe assumption that getId() might attempt to modify the object but at the same time,
it also notices that the object is const; so any attempt to modify the const object should be an error.
Hence compiler generates an error message.

https://stackoverflow.com/questions/3141087/what-is-meant-with-const-at-end-of-function-declaration
A "const function", denoted with the keyword const after a function declaration, makes it a compiler error for this class function to change a member variable of the class. However, reading of a class variables is ok inside of the function, but writing inside of this function will generate a compiler error.
