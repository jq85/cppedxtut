# EXCEPTION SAFETY
===================

The basic tools provided by the C++ language for exception safety are:
  - try-catch
  - resource acquisition is initialization (RAII).

RAII is a technique that allows the ownership of a resource be given to a scoped object.
We looked at how this can be applied to a scopeguard scenario that allows us
to ROLL BACK a transaction if a subsequent one fails in a commit all or nothing situation.

We have also covered the try-catch block syntax and its use in the call stack and how to pass error information up the call stack.

STL & EXCEPTION SAFETY
The Standard template library (STL) will provide exception safety as long as we provide it with operations which adhere to the library's basic requirements.
The STL will not throw exceptions that leave memory leaks or containers in an invalid state, and thus user defined operations need to do the same.

GOOD PRACTICES
 - When updating an object don't destroy the old one until the new one is fully constructed.
 - Before throwing an exception release all acquired resources that are not owned by another object.
   This is what RAII guarantees such that the destructor will release all resources that the constructor has/tried to obtain.
 - Don't leave objects in an invalid state before throwing an exception;
   this means that they can be accessed and destroyed and don't throw exceptions from the destructor as this would lead to program termination.
 - Representing resources as classes that obey the RAII policy is the best exception safe way of OBTAINING RESOURCES,
   because either the constructor succeeds to obtain them or it throws an exception and the objects destructor will be called which should release any resources acquired in the constructor.
