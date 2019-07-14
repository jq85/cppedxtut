#include "Body.h"


class Handle
{
private:
    /*
    * Handle is efectively a wrapper for the Body class
    * So the Handle points
    * to the Body and the Handle class will define methods that encapsulate all
    * operations on Body
    */
    Body * body;   // The "handle" class typically maintains an internal instance of the "body" class.


public:
    Handle();
    ~Handle();

    void someOperationOnBody();
};


/*
So this is an example of delegation in C++. The Body class does
some stuff in the background and the Handle class is the delegated
wrapper. It's the Handle class that the clients see. They don't even know
about the Body class's existence, and that's good because it means that you
can change how the Body class is implemented later and the rest of the
world will be oblivious, because they didn't even know it existed in the first
place. And this decoupling is very important when you have large systems.
*/
