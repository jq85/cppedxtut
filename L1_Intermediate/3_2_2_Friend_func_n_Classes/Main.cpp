#include "Handle.h"

/*
* This demonstration illustrates the handle-body idiom using friend classes.
* The intent of this idiom is to shield client code from the details of the "body" class,
* so that its implementation can vary dramatically without impacting the rest of the application.
*/
int main()
{
    Handle h;
    h.someOperationOnBody();

    return 0;
}

/*
* So in
* the client code, in main() we create a Handle object and we invoke a method on
* the Handle object. No mention of Body at all. I can change the Body class in any
* way I want. The client code isn't gonna be affected in any way whatsoever. So
* that's an example of friend classes. The fact that the Body class had private
* state, which it wanted the other class to be able to manipulate. So
* the Handle implementation accesses some data which is actually private notice,
* and it can do that because Handle is a friend of Body. So the Handle class is
* allowed to access private data in Body because Handle is a friend.
*/
