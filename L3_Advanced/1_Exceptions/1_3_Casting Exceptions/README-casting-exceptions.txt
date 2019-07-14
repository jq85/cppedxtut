# CASTING EXCEPTIONS
=====================

Static Cast, Const Cast, Dynamic Cast and Reinterpret Cast.


## STATIC CAST
--------------
Static Cast is used to convert from one type to another.
Primarily:
  - a pointer from a base class to a derived class,
  - from a derived class to a base class.
They should not be used to cast between pointer and non pointer types.
There is no run time check done to ensure the cast results in a full type of the target type so the user has to ensure the type cast is safe.


## CONST CAST
-------------
Const Cast is used to add or remove the const modifier to a variable.
This allows the developer to:
  - make a non modifiable variable modifiable,
  - make a modifiable variable non modifiable.
Const cast can also be used to change a variable's volatile modifier.
Volatile is used to tell the compiler the variable can be modified by another process,
so when it is used it should check the value every time, instead of storing it in the cache and re-using it.


## DYNAMIC CAST
---------------
Dynamic cast does a run time type check when performing the cast unlike the const cast.
This means it is safer to use when you know less about the types involved.
For instance, if you try to use a dynamic cast to convert a Base class to a derived class
it will most likely return zero if the base class is not a complete instance of the derived class which would be pointless.


## REINTERPRET CAST
-------------------
Reinterpret cast will convert pointers between types and integers.
Since reinterpret cast does not check the pointer type or the type pointed to,
it is possible to cast between unrelated and incompatible types,
 and thus any dereference of the cast is likely to fail, thus reinterpret cast is not safe.


## EXAMPLES
-----------
Here are some examples of the above casts.

    #include <iostream>
    #include <string>
    #include <type_traits>

    using namespace std;

    class MyBase {};

    class MyDerived : public MyBase {};

    class UnRelated {};

    int main() {

        MyBase* mb = new MyBase();

        MyDerived* md = new MyDerived();

        cout << "The type of mb is " << typeid(mb).name() << endl;
        cout << "The type of md is " << typeid(md).name() << endl;

        //Cast MyBase to MyDerived, Not safe as MyDerived can contain members not in MyBase.

        MyDerived* md2 = static_cast<MyDerived*>(mb);

        //Cast MyDerived to MyBase, Safe as MyDerived Contains MyBase public members from inheritance.

        MyBase* mb2 = static_cast<MyBase*>(md);

        cout << "The type of mb2 is " << typeid(mb2).name() << endl;
        cout << "The type of md2 is " << typeid(md2).name() << endl;

        //Cleanup
        delete mb;
        delete md;

        int myint = 5;

        cout << "The type of myint is " << typeid(myint).name() << " with value " << myint << endl;

        //Cast int to double, safe as precision of double is greater.

        double mydouble = static_cast<double>(myint);

        printf("The type of mydouble is %s with value %f \n",typeid(mydouble).name(),mydouble);


        //Dynamic cast
        MyDerived* md3 = new MyDerived();
        MyBase* mb3 = dynamic_cast<MyBase*>(md3);

        cout << "The type of md3 is " << typeid(mb3).name() << endl;

        //clean up
        delete md3;

        //Const cast
        const int myconst = 5;
        volatile int myvolatile = 9;

        int* nonconst = const_cast<int*>(&myconst);
        int* nonvolatile = const_cast<int*>(&myvolatile);

        //Can't print typeid's of const and volatile.

        //Reinterpret cast.

        MyBase* mb4 = new MyBase();
        UnRelated* urc = new UnRelated();

        //Possibly unsafe cast.
        MyBase* rcast = reinterpret_cast<MyBase*>(urc);

        cout << "The type of rcast is " << typeid(rcast).name() << endl;

        //cleanup
        delete mb4;
        delete urc;

        return 0;
    }
