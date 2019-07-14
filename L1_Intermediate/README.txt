https://courses.edx.org/courses/course-v1:Microsoft+DEV210.2x+3T2018/course/

#INTRODUCING MEMORY MANAGEMENT IN C++
=====================================

You should be aware that a computer contains a finite amount of physical memory.
Operating systems manage that memory and are responsible for allocating memory to applications that are currently executing.
Within certain limits, the operating system (OS) can control the amount of memory,
but at the same time, it still attempts to provide memory to an application when it requests more.

# SWAPPING
==========
The OS can use various methods such as swapping,
where it uses a portion of storage space on the fixed disk to move data and programs out of main memory and to the local disk,
in order to permit a running application to have memory resources.   There are limits.

Applications can become memory hogs and cause issues for computer performance when they request and use large amounts of memory.
It takes considerable resources to swap data and programs to the local disk,
so making an application as efficient as possible in terms of memory usage is an important consideration when coding your app.

Every variable that you create in your code,
every object that you instantiate,
and every resource that you open,
has an impact on computer memory usage and application performance.

# STACK
========
Some aspects of your code, such as non-object data types, like int, double, bool,
are scoped in a specific way and stored in the logical division of memory known as the stack.
When these variables go out of scope in your code, the memory on the stack is reclaimed automatically.
NOT SO MUCH WITH OBJECTS.
Each time you instantiate an object in your code,
you request memory to be set aside to store that object and all its data, which may include other objects.
Without going into specific details, the system uses a tracking mechanism for objects that are in use in an application.
It does so in order to ensure that the objects are available to your code when needed.

# RELEASE OBJECTS
=================
Only when YOU SPECIFICALLY INDICATE THAT AN OBJECT IS NO LONGER REQUIRED (deleting it in code), does the system release this hold on the memory used for that object.
As a result, if you forget to release object resources in our code,
they will continue to use the memory allocated and not release it back to the system.

# MEMORY LEAK
=============
A common occurrence, unfortunately, in unmanaged code, is something known as a memory leak.
This is where:
  - an application instantiates objects,
  - doesn't release the object when finished,
  - and continues to request memory for more object creation.
Eventually, the system will run out of memory and the OS will halt the application, or the OS may even crash.

# MEMORY ALLOCATION/DE-ALLOCATION METHODS
=========================================
This section looks at methods for managing the allocation of memory-consuming resources in your code,
and explains the steps necessary to ensure you are de-allocating memory that is no longer required by your application.
