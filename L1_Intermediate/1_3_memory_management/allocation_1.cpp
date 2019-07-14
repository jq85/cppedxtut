/*
* Allocating memory during runtime of an application is a common requirement.
* For example, you may not know how many objects your application will need until the application is running.
* Allocating memory to newly created objects at runtime makes use of pointers.
* This is the only way to gain access to memory for new objects when your application is running.
* A small code sample will serve to illustrate this.
*
* In this code sample, we see the use of the keyword new.
* We also notice that, unlike in previous code samples with pointers, we didn't assign a variable to the pointer.
* Instead, we told the compiler that we wanted to create a pointer to an int and then,
* when the program runs, to dynamically assign some memory to hold an int value.
* We won't know what the memory address is until run time.
* We also did the same thing with a pointer to double.
*/

#include <iostream>

using namespace std;

int main()
{

    // declare a pointer to int and allocate space for it
    // with the keyword new
    int *pInt = new int;

    // declare a pointer to double and allocate space for it
    // with the keyword new
    double * pDouble = new double;

    /*
    * Because an int, at least on the computer used for this course authoring, is 4 bytes and a double is 8 bytes,
    * the operating system allocates 4 bytes for a value to be stored, starting at the memory address in pInt,
    * and 8 bytes for the double value, to be stored in the memory of the computer, starting at the address in pDouble.
    */

    // store the value 3 in the memory location
    // pointed to by pInt
    *pInt = 3;

    // store the value 5.0 in the memory location
    // pointed to by pDouble
    *pDouble = 5.0;

    // Use dereference (aka indirection) to get the value
    cout << "value stored at pInt = " << *pInt << ", memory address = " << pInt << endl;
    cout << "value stored at pDouble = " << *pDouble << ", memory address = " << pDouble << endl;

    cout << "size of pInt = " << sizeof(pInt) << endl;
    cout << "size of *pInt = " << sizeof(*pInt) << endl;
    cout << "size of pDouble = " << sizeof(pDouble) << endl;
    cout << "size of *pDouble = " << sizeof(*pDouble) << endl;

    //DEALOCATION to release memory
    delete pInt;
    delete pDouble;

    return 0;
}
