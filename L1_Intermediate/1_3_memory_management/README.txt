https://courses.edx.org/courses/course-v1:Microsoft+DEV210.2x+3T2018/course/
For more information , you can see:
C and C++ with Visual Studio: https://aka.ms/edx-dev210.2x-vs02
Visual Studio: https://aka.ms/edx-dev210.2x-vs01

# ALLOCATING MEMORY
====================

Allocating memory during runtime of an application is a common requirement.  For example, you may not know how many objects your application will need until the application is running.  Allocating memory to newly created objects at runtime makes use of pointers.  This is the only way to gain access to memory for new objects when your application is running.  A small code sample will serve to illustrate this.

    // declare a pointer to int and allocate space for it
    // with the keyword new
    int *pInt = new int;

    // declare a pointer to double and allocate space for it
    // with the keyword new
    double * pDouble = new double;

    // store the value 3 in the memory location
    // pointed to by pInt
    *pInt = 3;

    // store the value 5.0 in the memory location
    // pointed to by pDouble
    *pDouble = 5.0;

In this code sample, we see the use of the keyword new.  We also notice that, unlike in previous code samples with pointers, we didn't assign a variable to the pointer.  Instead, we told the compiler that we wanted to create a pointer to an int and then, when the program runs, to dynamically assign some memory to hold an int value.   We won't know what the memory address is until run time.  We also did the same thing with a pointer to double.

We use the dereference operator to assign a value to the memory location pointed at by pInt and pDouble.  Again, we have no idea what these memory addresses are because they are allocated dynamically during runtime.   The application requests some memory large enough to store an int value in and a double value.   Because an int, at least on the computer used for this course authoring, is 4 bytes and a double is 8 bytes, the operating system allocates 4 bytes for a value to be stored, starting at the memory address in pInt, and 8 bytes for the double value, to be stored in the memory of the computer, starting at the address in pDouble.

It's very important to note, at this point, that pInt and pDouble are both the same size, in this case 4 bytes, but the memory space storing the values are 4 bytes and 8 bytes respectively.  But how can that be when one is an int and the other is a double?

Quite simply, a memory address is a fixed size on a specific computer architecture.  In this case it takes 4 bytes to hold a memory address.  The start of that memory address is what pInt and pDouble point to.  The computer must know the data type in order to work out how much total memory is assigned to that location.

As a concrete example, when this code was executed, the memory address for pInt was set to 00F1FBA8 and the ending memory address was 00F1FBAC and the starting address for pDouble was 00F21330 with an ending address of 00F21338.  Doing a little hexadecimal math we can see that pInt indeed spans 4 bytes and pDouble spans 8 bytes.  Recall that in hexadecimal, we only go as high as 9 then move on to letters so that we would count from the ending 8 in pInt to C as in 9, A, B, C.  That's 4 positions. (in order to get to the ending memory address for these pointers, simply increment the pointer as in pInt++, and the computer will increase the memory address by the number of byes indicated by the data type pointed to).



# RELEASING MEMORY: DEALLOCATION
================================

One final point that we need to make in your use of pointers and dynamic memory allocation is releasing memory.
Each time you allocate memory in your application, it is reserved by the operating system so that other applications cannot access that memory address.

This has security implications as well as importance for separation of application code to prevent system wide crashes if an errant application behaves badly.

MEMORY LEAK
If you do not release the memory in your application, the operating system will not reclaim it and this is known as a memory leak.
It is compounded if your application continues to dynamically allocate memory and doesn't release it.

DELETE FOR EVERY NEW
Delete is used for these particular types of pointers because we're pointing to intrinsic or built-in data types.
Similar to the destructor for objects.
The simple way of releasing your allocated memory is to use the keyword delete.
For the sample code above, you would make use of the delete keyword as demonstrated here.

    // declare a pointer to int and allocate space for it
    // with the keyword new
    int *pInt = new int;

    // declare a pointer to double and allocate space for it
    // with the keyword new
    double * pDouble = new double;

    // store the value 3 in the memory location
    // pointed to by pInt
    *pInt = 3;

    // store the value 5.0 in the memory location
    // pointed to by pDouble
    *pDouble = 5.0;

    delete pInt;
    delte pDouble;

We have simply issued the delete keyword in reference to each pointer we have in the application code.
The operating system will now reclaim the memory used by those pointers and our code no longer has a memory leak.
Use whatever method makes sense to you to ensure that memory is released like using a delete keyword for every new keyword.

And again, this is using just intrinsic or simple data types.
You'll revisit dynamic memory allocation using the new keyword
when we delve deeper into some more of the class files.
And working with objects that are class files
rather than intrinsic data types in the next module.





Which of the following is a valid way to create an alias for a variable in C++? Note that data types are excluded for simplicity.
&refVariable = variable     YES
*refVariable = variable     NO
refVariable = &variable     NO
refVariable = *variable     NO



https://courses.edx.org/courses/course-v1:Microsoft+DEV210.2x+3T2018/courseware/ebe558b31dd14a46a15040bd355ff9f9/e7225262c56d48108341251bcf87f255/?child=first
# DYNAMIC MEMORY ALLOCATION WITH CLASSES
========================================
transcript:

In this demonstration, we'll take a look
at the use of dynamic memory allocation
with the class file. We will see an example of how we
dynamically allocate memory
for an object that we create in our code and then how the destructive plays
a part in the releasing of the memory resources when we delete that
object in our code itself.
So what I've done is recreated the person class here and we can see that we
have our three private member variables. For first name, last name
and age. We have our three constructors. We have a single destructor
and then ofcourse, we have encapsulated our private member variables
with setters and getters and then, we have our SayHello function
here at the end.
Now we're not making use of everything within this class for the example as we
go through this demonstration because again it's just designed to give you
an idea of how the destructor plays a part in your class, when we delete
the object in memory. So the only thing that I've really changed in our
person class, everything here is the same. We have our default constructor,
the two argument constructor,
the three argument constructor and of course our setters
and getters but the only thing really that's different is this line of code
that I've written in the destructor itself. But this is not, something you
typically do in your code but for demonstration purposes,
I put this output statement here,
so that we can see in the console window when the destructor
is actually called. So we look at our Driver program,
for the purpose of testing.
We see that we will create a Person object called pOne
and it's a pointer variable.
So, we use the new keyword to instantiate memory for this object.
We use the three argument constructor to build that object in memory
and then what we will do is,
issue a statement here just to show that we're actually dealing
with some data for the pOne object that we've created and we will
return the first name that we set in the constructor and then just to show
that it does actually exist in memory, we will output a
a memory address which has been assigned to that variable
and again, take note that we're using the address of operator here.
And then once we've completed that,
we will basically destroy the object, indicating to
the operating system that we're finished, with the object and it can
take that memory back and we do so by calling the Delete keyword.
Now you may remember this from earlier demonstrations where we show deleting
objects through dynamic memory allocation that we
just value references. And in this case, we're dealing with a
reference variable for class.
So, a destructor will actually be called once this delete statement
is executed. So let's go ahead and run this code and see what happens.
And we wait for it to compile and the command window pops up.
And in our console window, we can see that, we didn't
indeed a sign first name Tom and that's what we pull back out with the
get first name parameter in that line of code right here.
Then we ask for the memory address of pOne
and we've been given a memory address.
In this case, it ends in FE28 and then once we call the Delete keyword, we can
see that the code within that destructor was actually executed
and we output the Person destructor called statement to tell us
that the destructor was actually called.
Now just by way of an example and again proving how
dynamic memory allocation works, I'll press the Enter key to end that
and then, I'll execute the code one more time
and you notice that, the memory address now has changed.
So we've dynamically assigned memory for each one of those objects that we
created. But our application is not continuing to consume that memory
because our destructor has been called in each instance.
So get a relatively quick short demonstration just showing how we can
dynamically allocate memory for our objects in our code when we create new
instances of the class files that we've created
and through the use of the destructor.
We saw that, this simple line told us that the destructor was called simply
by us, initiating a delete statement on that particular object
and the memory was released back to the operating system.
