#include <iostream>
/**
 * MSDN defines storage class as,
 * "A storage class in the context of C++ variable declarations is
 * a type specifier that governs the objects':
 *  - lifetime
 *  - linkage
 *  - memory location
 *
 * LIFETIME:
 * Lifetime refers to how long the variable "hangs around" in memory
 * from the point at which it is declared and the point at which it is destroyed (the memory it used is released).
 * For the most part, once a variable goes out of scope, its memory will be released back to the operating system for reuse.
 *
 * LINKAGE:
 * Linkage refers to the visibility of a variable outside of the file that contains it.
 *
 * MEMORY ALLOCATION:
 * Memory location refers to the place in which the variable is found in memory.
 * This doesn't refer to the physical memory address as you might expect
 * but more to the logical division of memory that applies to a running application.
 * logical division: There are two logical memory areas known as:
 *   - STACK:
 *     location in memory where intrinsic data is stored as well as memory addresses (pointers).
 *     It operates in the form of data structure known as a stack.
 *     Like a cafeteria stack of plates, items are pushed on top of the stack and other items are pushed further down.
 *     To remove an item from the stack, it is popped off, used, and discarded.
 *   - HEAP
 *     (heap or free store),
 *     is a pool of memory that is used to store objects that dynamically allocated at run time by your application.
 *     Objects are created or destroyed on the heap by using specific instructions in your program code.
 *
 * SCOPE:
 * term used describe where an identifier is visible in a program.
 * An identifier is a variable, constant, class, etc.
 * Your identifier is visible from the point in which you have declared it until the end of its scope.
 *
 * STORAGE CLASS TYPES: STATIC, EXTERN, THREAD_LOCAL:
 * STATIC:
 * Identifiers declared with static are allocated when the program starts and deallocated when the program execution ends.
 * Declaring a variable as static in a function means that the variable will retain its value between calls to the function.
 *
 * EXTERN:
 * used to declare an object that is defined in another translation unit of within the enclosing scope but has an external linkage.
 *
 * THREAD_LOCAL:
 * declares that the identifier is only accessible on the thread in which it is created.
 * This prevents sharing of the identifier across multiple threads in the same application.
 * This is part of the C++11 standard.
 *
*/
using namespace std;

int main()
{
}
