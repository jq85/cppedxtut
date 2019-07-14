http://www.cplusplus.com/doc/tutorial/classes/

INTRODUCTION
Classes enable you to create your own custom, self-contained, and reusable types.
A class file is often considered a blueprint for objects that you use in your code.
Typically you will create class files to help model real-world objects in your code.

An example of this might be the software that manages a bank ATM.
The software would need to understand the concept of customers, accounts, transactions, etc.
It's far easier to implement the software application by modelling these real world objects as software objects (classes) in your code.


HOW IT LOOKS IN MEMORY:
So this is effectively anytime we're building new user types,
which are using classes, we're just combining smaller types or
more basic types like ints and floats and doubles into a larger whole.


CREATING CLASSES AND MEMBERS
In C++, a class is a programming construct that you can use to define your own custom types.
When you create a class, you are effectively creating a blueprint for the type.
The class defines the behaviors and characteristics, or class members, which are shared by all instances of the class.
You represent these behaviors and characteristics by defining methods and fields within your class.

Suppose you create a class to represent a rectangle shape in your program.
You use the class keyword to declare a class, as shown in the following example:


DECLARING A CLASS
class Rectangle
{
public:
    int _width;
    int _height;
};

Here we have declared a class called Rectangle and given it two public member variables called _width and _height, that will be used to represent the width and height of our rectangle.
Note that they are accessible directly because they are public, as a result of the public: modifier.


USING A CLASS
Now that we have a class created to represent a rectangle, we can use that in our code to create instances of a rectangle in our program.
When we create a new rectangle from this class, it is known as a rectangle object and will be given a unique name.
That way ,we can refer to it in our program directly and distinguish it from other rectangle instances that we might create, should our program require more than one.

void main()
{
  Rectangle outer;
  Rectangle inner;

  outer._width = 10;
  outer._height = 10;

  inner._width = 5;
  inner._height = 5;
}


CLASS INITIALIZATION
One method to initialize the values of the class members is to use the "new" keyword.
Initialization is an important part of working with your classes in C++.
Even when using intrinsic data types, if you do not initialize the variable for that type and you access it in your code, you will end up with whatever values are stored in the memory location that the variable refers to.
This is something you want to avoid doing.
You should always initialize your types in C++;

C++ offers a couple of options for initializing your classes.
You can initialize the member variables by using the dot operator and setting the values explicitly,
or you can include a constructor in your class that is responsible for initialization the member variables.
You'll see this in the demo video next as well as more information in the topic on encapsulation.
