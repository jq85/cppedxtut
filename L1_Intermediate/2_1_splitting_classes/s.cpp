/*
* If you compile and run the following code, you will notice the memory address of num output to the console window.
* On my first run, the address for num was 001CF79C and on the second run it was 0018FD38.
* Subsequent runs will offer up different memory addresses showing how the "identity" of the variable is only good for the duration of its lifetime.
* The values you see may be different that these addresses returned for this execution of the program.
*/

// #include "stdafx.h"
// #include "windows.h"
#include <iostream>

using namespace std;

int main()
{

    //BASIC POINTER USE
    int num = 3;
    //int *pNum;//WARNING: never declare a pointer without initialization.
    int *pNum = &num;

    cout << "num   "  << num   << endl;//print variable's value
    cout << "&num  "  << &num  << endl;//print variable's address, i.e. address of the variable.
    cout << "pNum  "  << pNum  << endl;//print pointer value, i.e. address it points to.
    cout << "&pNum "  << &pNum << endl;//print pointer's address.

    //BASIC DEREFERENCE OPERATOR USE
    // Use dereference (aka indirection) to get the value
    cout << "*pNum " << *pNum << endl;
    *pNum = 45;//to get to the value that is being stored at the memory address.
    cout << "*pNum " << *pNum << endl;
    cout << "num   " << num << endl;//the underlying value has been modified.

    //DIRECT ACCESS

    return 0;
}
