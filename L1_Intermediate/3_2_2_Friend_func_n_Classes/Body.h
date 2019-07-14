#pragma once

class Handle;  // Forward reference of the "handle" class, so the compiler knows about it.

class Body
{
    friend class Handle; //Handle class will know nothing about Body class
                        //the compiler does not need to know more about Handle class now

private:
    int someData;
};
