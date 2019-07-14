# HANDLING ALLOCATION FAILURES
===============================

Handling allocation failures
Allocation failures are usually defined by the bad_alloc exception and can be generally divided into two areas:
  - Memory exhaustion
  - Heap corruption

When dealing with memory allocation errors due to memory exhaustion
there are usually not many options for recovery since it means the system has run out of memory.
The standard way of working would be to use the try-catch block around memory allocation calls so any bad_alloc exceptions thrown are caught.
If you have run out of memory you cannot log to file or create any more exception information to pass up the stack,
one option is to allocate some memory when the program starts for emergence purposes such as this,
which would allow you to log exception information to file for instance.

RESERVE MEMORY
To allocate memory from a reserved pool you would use the placement 'new' syntax.
If you are getting allocation errors due to heap corruption due to dangling pointers,
then the try-catch block should log the necessary information and or pass the exception up the call stack to allow a graceful termination of the program.
Dangling pointers are a bug and would need to be fixed.

STL
Allocation failures can also be thrown indirectly by using the standard template library,
for example the containers need to allocate memory to store the elements.

HEAP CORRUPTION
When you do memory resize calls it is important to make sure any iterators on resized collections are also renewed
as after a resize they would have invalid indexes.
Any index operations such as std::vector::operator[] need to be within the boundary range of the elements otherwise they can cause heap corruption.
There are heap debuggers such as GNU valgrind or Visual Studio's Memory usage tool that can aid you in resolving heap issues.

The following code is an example of capturing a bad_alloc exception in a try-catch block.



  #include <iostream>
  #include <new>

  using namespace std;

  int main()
  {
      try {
          while (true) {
              int* intarray = new int[99999ul];
          }
      }
      catch (const std::bad_alloc& e) {
          cout << "bad_alloc caught: " << e.what() << endl;
      }
      return 0;
  }



The code goes around a loop allocating an integer array until bad_alloc is thrown which is caught by the catch and prints a message to standard output.






# CUSTOMISING MEMORY ALLOCATION
===============================

Override new operator to customise memory allocation.
Most of the time the default C++ memory allocator/deallocator will be sufficient for everyday purposes so why would we want to implement our own.

  Maybe we want to allocate memory from a custom memory pool instead of the free store,
  one possible scenario was covered in the previous topic of memory handling,
  where a bad_alloc exception is thrown due to memory exhaustion
  so we want to log to file but need to use memory we reserved at the start of the program.

  Maybe we want to implement a garbage collector or allocate memory on the video buffer.
  We could achieve some of these requirements using placement new,
  however this is not a replacement for a global new allocator if you wanted to replace the allocator in an entire code base.

Previously I have mentioned the Loki library which also implements its own small object allocator
because these small objects use polymorphic behaviour they need to live on the heap and not the stack.
Some implementations of the new operator have bad performance
due to speed of allocation and or using too much memory in the allocation process and likewise for the free allocator.

So now we have discussed various reasons for implementing the new and free allocators let's have a look at a small example.



  #include <new>
  #include <iostream>

  using namespace std;

  //Allocator class
  class MyNewDeleteAllocator {
  public:
      MyNewDeleteAllocator() {}
      ~MyNewDeleteAllocator() {}
      static void* operator new (size_t size);
      static void operator delete (void *p);
  };

  void* MyNewDeleteAllocator::operator new (size_t size){
      void *p;
      p = malloc(size);
      if (p == NULL) {
          //Throw bad_alloc.
          std::bad_alloc exception;
          throw exception;
      }
      cout << "MyNewDeleteAllocator::operator new called with size_t " << size << endl;
      return p;
  }

  void MyNewDeleteAllocator::operator delete (void *p){
      cout << "MyNewDeleteAllocator::operator delete called. " << endl;
      delete[] p;
  }


  int main()
  {
      MyNewDeleteAllocator *p = new MyNewDeleteAllocator; //Create MyNewDeleteAllocator object.

      delete p; //Delete MyNewDeleteAllocator object.

      return 0;
  }



The above program creates a new MyNewDeleteAllocator object and we can see from the output that the new and delete operators of this class are called.
This is an example of how to override the new and delete operators locally.
It is possible to override them globally however this is not recommended if your application uses other libraries
as it would cause those included libraries to use your overridden new and delete as well.
You could throw a custom exception in the new operator is the memory allocation fails
this would allow you to create the exception on some reserved memory
so if the application suffers memory exhaustion the error will still be created/logged.




# CACHING
==========

Caching
Caching is the ability to retrieve often used data quickly,
so the data needs to be stored somewhere for it to be retrieved.
The std::vector is most often used for this since it is guaranteed to be stored in contiguous memory
which allows the linear search to be efficiently performed.
Now most caching solutions involve a Least recently used algorithm
to remove least recently used data from the container so the most recently used is near the front of the container which supports fast search times.

Using const variables will allow the compiler to store the value in the register for quick retrieval
later The register keyword can be used to tell the compiler that it will be accessed a lot
and to keep the variable in a machine register.
For instance, you may put a loop index in a register as it will be accessed many time around the loop which would give a performance benefit.
For example,

  for(register int i = 0; i < 9999999; i++){}

When accessing array indices try to do it sequentially as that's what the machine is expecting
i.e. array[j][t] is followed by array[j][t+1] but array[j+1][t] is probably still in ram memory and not the cache.

Data alignment can also help with cache access.
When memory is read by the cpu it reads it in as multiples of word size.
By aligning your data with the boundaries of multiples of word size you make the cache read/writes more efficient.
In c++11 we have the alignas and alignof keywords:

  - alignas allows us to align a variable to a multiple number of bytes
  - alignof gives us the required alignment of a type in bytes. For example.



  #include <iostream>
  #include <vector>
  #include <ctime>

  using namespace std;

  int main(){

      std::vector<int> myvec;
      std::vector<int> myvec2;
      clock_t clock_time;

      clock_time = clock();
      for(int i = 0; i < 9999999; i++) {
          myvec.push_back(999);
      }
      clock_time = clock() - clock_time;

      printf("Loop without index in register took %f seconds \n", ((float)clock_time/CLOCKS_PER_SEC));
      //clear vector.
      myvec.clear();

      //start timer
      clock_time = clock();
      for (register int t = 0; t < 9999999; t++) {
          myvec2.push_back(999);
      }
      clock_time = clock() - clock_time;
      //end timer.

      //clear vector.
      myvec2.clear();


      printf("Loop with index in register took %f seconds \n", ((float)clock_time / CLOCKS_PER_SEC));

      //c++11 alignment keywords
      alignas(16) int a[4];
      alignas(1024) int b[4];

      //Output padded results
      printf("%p\n", a);
      printf("%p\n", b);

      if (_alignof(a) == 16) {
          cout << "int b aligned to 16 bytes" << endl;
      }

      if(_alignof(b) == 1024) {
          cout << "int b aligned to 1024 bytes" << endl;
      }

      return 0;
  }



This code demonstrates the use of the register key word in a loop and also alignas and alignof keywords. The above code gave me the following output on my machine.

Loop with index in register took 24.811001 seconds
Loop without index in register took 25.607000 seconds
0018F390
0018EC00
int b aligned to 16 bytes
int b aligned to 1024 bytes
Press any key to continue . . .
