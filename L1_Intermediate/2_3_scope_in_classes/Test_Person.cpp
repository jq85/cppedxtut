#include <iostream>
#include "Person.h"

int main()
{
    Person p;

    p.SetFirstName("Gerry");
    std::cout << p.GetFirstName() << std::endl;

    // this line will output an invalid age message due to the
    // validation check in the SetAge() function
    p.SetAge(-5);

    // this line will not work because firstName is private
    p.firstName = "Gerry";//WARNING: COMPILER FAILS
    // p.SetFirstName("John");
    // std::cout << p.GetFirstName() << std::endl;

    return 0;
}
