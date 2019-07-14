#include <iostream>

using namespace std;

void passByRef(int &num1);

/*
* Because we passed num as a reference,
* C++ was able to access the contents of num directly in memory
* rather than a copy of the value held by num as in the passByValue() example.
* For more information , you can see: C and C++ with Visual Studio: https://aka.ms/edx-dev210.2x-vs02
*/
int main()
{

    int num = 3;
    cout << "In main()" << endl;
    cout << "Value of num is " << num << endl;
    cout << "Address of num is " << &num << endl;

    passByRef(num);

    cout << "Back in main and the value of num is  " << num << endl;


    return 0;
}

/*
 * input param is ref_type
 * BUT WARNING num1 ref type becomes an "alias" for num.
 * it's not the same as saying that we're passing num as a reference.
 *
*/
void passByRef(int &num1)
{
    cout << "In passByRef()" << endl;
    cout << "Value of num1 is " << num1 << endl;
    cout << "Address of num1 is " << &num1 << endl;

    // modify num1 which will now change num
    num1++;

    cout << "num1 is now " << num1 << endl;
}
