#include "MyClass.h"

/*
 * Don't prefix friend functions with the ClassName::function syntax, because they are not members of the class.
 */
// void MyFriend::SomeExternalFunction(MyClass & targetObject)
void SomeExternalFunction(MyClass & targetObject)
{
    // Access any members on the target object, i.e. public, private, or protected members.

}
