#include "Handle.h"

Handle::Handle()
{
    body = new Body;  // Creates the underlying "body" object
}

Handle::~Handle()
{
    delete body;      // Delete the underlying "body" object.
    /*
    * the Handle object has custody over the Body. The Handle creates the
    * Body initially and Handle destroys the Body at the end. It completely owns the
    * lifetime of the Body.
    */
}

/*
* And here's the implementation of the wrapper method.
* This is the method that the client code will call, some operation, underneath the
* surface, the Handle just does some other work on the Body. But of course that's
* away from the client's view. All the client sees is the name of this method.
*/
void Handle::someOperationOnBody()
{
    body->someData = 42;    // Perform operations on the underlying "body" object.
}
