#include <iostream>
#include <string>
#include <type_traits>
#include <typeinfo>//error: must #include <typeinfo> before using typeid

using namespace std;

class MyBase {};

class MyDerived : public MyBase {};

class UnRelated {};

/*
*
*/
int main() {

    /*
    * STATIC CAST
    */
    MyBase *mb = new MyBase();//create a base class pointer and allocate a new base class object
    cout << "The type of mb is " << typeid(mb).name() << endl;

    MyDerived *md = new MyDerived();//create a derived class pointer, and locating the direct class object
    cout << "The type of md is " << typeid(md).name() << endl;


    //Cast MyBase to MyDerived, Not safe as MyDerived can contain members not in MyBase.
    MyDerived *md2 = static_cast<MyDerived*>(mb);
    cout << "The type of mb2 is " << typeid(mb2).name() << endl;

    //Cast MyDerived to MyBase, Safe as MyDerived Contains MyBase public members from inheritance.
    MyBase *mb2 = static_cast<MyBase*>(md);
    cout << "The type of md2 is " << typeid(md2).name() << endl;

    //Cleanup
    delete mb;
    delete md;

    int myint = 5;
    cout << "The type of myint is " << typeid(myint).name() << " with value " << myint << endl;

    //Cast int to double, safe as precision of double is greater.
    double mydouble = static_cast<double>(myint);
    printf("The type of mydouble is %s with value %f \n",typeid(mydouble).name(),mydouble);


    /*
    * DYNAMIC CAST
    */
    MyDerived* md3 = new MyDerived();
    MyBase* mb3 = dynamic_cast<MyBase*>(md3);
    cout << "The type of md3 is " << typeid(mb3).name() << endl;

    //clean up
    delete md3;

    /*
    * CONST CAST
    */
    const int myconst = 5;
    volatile int myvolatile = 9;

    int *nonconst = const_cast<int*>(&myconst);
    int *nonvolatile = const_cast<int*>(&myvolatile);

    //Can't print typeid's of const and volatile.

    //Reinterpret cast.
    MyBase* mb4 = new MyBase();
    UnRelated* urc = new UnRelated();

    //Possibly unsafe cast, because we have no guarantee that the unrelated class type has the same members as the basic class type
    MyBase* rcast = reinterpret_cast<MyBase*>(urc);
    cout << "The type of rcast is " << typeid(rcast).name() << endl;

    //cleanup
    delete mb4;
    delete urc;

    return 0;
}
