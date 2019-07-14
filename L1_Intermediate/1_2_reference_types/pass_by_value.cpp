/*
* References are commonly used with parameters to functions.
* The default mechanism used by C++ when calling a function,
* is to pass arguments into the parameters of that function, by value.
* This means that only the value is passed.
* This has one effect in a program as we see here.
*/
#include <iostream>

using namespace std;

//We declare our function prototype before main().
void passByValue(int);

int main()
{

    int num = 3;
    cout << "In main()" << endl;//We output a line indicating which function we are in (main())
    cout << "Value of num is " << num << endl;//And then what the value of num is (3).
    cout << "Address of num is " << &num << endl;

    //pass num as the argument to the num1 parameter.
    passByValue(num);

    cout << "Back in main and the value of num is " << num << endl;//we output the value for num, which is still 3, not 4.


    return 0;
}

void passByValue(int num1)
{
    cout << "In passByValue()" << endl;//We print a line indicating that we are inside the passByValue() function
    cout << "Value of num1 is " << num1 << endl;//and then output the value of num1 to show that indeed has the same value as num (3).
    cout << "Address of num1 is " << &num1 << endl;

    // modify num1, won't impact num
    num1++;

    cout << "num1 is now " << num1 << endl;
}
