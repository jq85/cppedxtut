# RECAP EXCEPTIONS
==================

You have previously seen the try-catch exception handling mechanism in the c++ language like in the following code.

#include <iostream>
#include <string>

  int main() {
      try{
          throw 6;
      }
      catch(int e) {
          std::cout << "Int exception thrown " << std::to_string(e) << std::endl;
      }
  }


This is the main mechanism provided in the c++ language for exception handling and should be used.
We will discuss other ways of extending this mechanism to allow us to implement more complicated error reporting when an exception occurs.



# STANDARD EXCEPTION CLASS HIERARCHY
=====================================
The Standard exception class hierarchy
The c++ standard library provides an exception base class that can be derived,
and allows us to override the what and ~exception virtual functions in our derived class.
This allows us to return a custom error message string,
and the destructor allows us to free any memory allocated on the heap with the operator new function.
For example

  #include <iostream>
  #include <exception>

  using namespace std;

  class derivedexception: public exception {
        virtual const char* what() const throw() {
          return "My derived exception";
        }
  } myderivedexception;

  int main () {
        try {
          throw myderivedexception;
        }
        catch (exception& e) {
          cout << e.what() << '\n';
        }
  }


In the first two lines, we include the input and output stream libraries and the standard exception base class.
The third line declares we are using the std namespace.
The fourth line declares our derived class called derivedexception
and that we are accessing the base class exception's public members.
The fifth line defines our overridden base class function what() which returns the const char* c string "My derived exception”.
The next two lines close the function and class scope.

The next line is the main entry point of the program,
then on line ten we open a try-block to place the following code under an exception inspection.
The next line throws an exception of type myderivedexception which transfers control to the exception handler.
The exception handler is declared with the keyword catch on line 13.
The type passed as a parameter to catch is compared to the type of the thrown exception,
in this case the type is exception and our class derivedexception inherits from exception so the handler for derived exception is executed
and when we invoke the function what() “My derived exception” is returned.

There are a number of exceptions in the standard library which derive from the standard exception base class.
The ones which derive from the exception base class are

  std::bad_alloc  //thrown by new
  std::bad_cast   //thrown by dynamic_cast
  std::bad_typeid  //thrown by typeid
  std::bad_exception
  std::logic_error  //thrown by reading the code
  std::runtime_error  //thrown when not detecable by code analisys
  std::bad_function_call  //c++11
  std::bad_weak_ptr   //c++11

Further there are some more exception which derive from std::logic_failure which are

  std::domain_error
  std::invalid_argument
  std::length_error
  std::out_of_range
  std::future_error  //c++11

And there are also some exception that derive from std::runtime_error which are

  std::overflow_error
  std::range_error
  std::underflow_error
  std::system_error  //c++11

Also the following inherit from std::bad_alloc

  std::bad_array_new_length

And the following inherit from std::system_error only in c++11

  std::ios_base::failure

All of these derive from std::exception and therefore can all be caught by the std::exception type.





# UNCAUGHT EXCEPTIONS
======================

If you define an ellipsis (...) as the parameter of an exception handler then it will catch any exception type that is thrown in its associated try-block.
This is most often used as a default exception handler when no other exception handler type matches.
This can be used as the default case of some chained exception handlers such as.

  #include <iostream>

  using namespace std;

  int main() {
      try {
          throw 20;
      }
      catch (int exc) { cout << "int exception." << endl; }
      catch (double exc) { cout << "double exception." << endl; }
      catch (...) { cout << "All other exception types." << endl; }

      try {
          throw 20.0;
      }
      catch (int exc) { cout << "int exception." << endl; }
      catch (double exc) { cout << "double exception." << endl; }
      catch (...) { cout << "All other exception types." << endl; }

      try {
          throw true;
      }
      catch (int exc) { cout << "int exception." << endl; }
      catch (double exc) { cout << "double exception." << endl;}
      catch (...) { cout << "All other exception types." << endl; }

  }
  You can also nest try-blocks and forward exceptions to the parent try-block using the throw keyword like so.

  try {
      try {
          //Do something here that causes an exception
          throw 10;
      }
      catch (int numb) {
          cout << "Caught int exception." << endl;
          throw;
      }
  }
  catch (...) {
      cout << "An error occurred." << endl;
  }





  An exception is uncaught if there is no associated exception handler to catch it. When this happens a call to terminate() is done automatically and any subsequent calls to termination functions that would normally be done during normal program execution does not happen, this includes calls to allocated objects destructor's functions.

  This is especially problematic when you consider RAII (Resource acquisition is initialization). If a destructor throws an exception during stack unwinding the whole program will exit. When an exception occurs, program execution moves to that exception's exception handler and all automatic variables between the throw and catch are destroyed, this process is called stack unwinding. Consider the following code segment

  #include <iostream>

  using namespace std;

  class throwexception {
  public:
      throwexception(); //Constructor

      ~throwexception();  //Destructor
  };

  throwexception::throwexception(void) {
      cout << "throwexception object constructed" << endl;
      //Constructor
  }

  throwexception::~throwexception(void) {
      //Destructor
      cout << "throwexception destructor called." << endl;
      throw 9;
  }

  int main() {
      try {
          throwexception texc;
          cout << "Throwing exception will cause termination of program." << endl;
          throw 7;
      }
      catch (...) {
          //Catch exception
          cout << "Main Exception caught" << endl;
      }
  }
  If you compile and run this code you will see the throwexception destructor is called and the program exits after printing out “throwexception destructor called”. So it is not considered good practice to throw exception in an objects destructor.






  Now consider the following situation. we want to update two vectors using the push_back function and either we update both vectors or neither of them to keep them synchronised. If we look at the std::vector documentation we will see push_back can throw an exception if the allocation fails. So If the first vector update succeeds but the second vector update fails then we have to roll back the update to the first vector. We could write some code like the following.

  #include <iostream>
  #include <vector>

  using namespace std;

  void updateVector(std::vector<std::string>& firstvector_, std::vector<std::string>& secondvector_, std::string newString) {
      firstvector_.push_back(newString);
      try {
          secondvector_.push_back(newString);
      }
      catch (...) {
          firstvector_.pop_back();
          cout << "second vector update failed." << endl;
      }
  }

  void updateVector2(std::vector<std::string>& firstvector_, std::vector<std::string>& secondvector_, std::string newString) {
      firstvector_.push_back(newString);
      try {
          std::bad_alloc excep;
          throw excep;
          secondvector_.push_back(newString);
      }
      catch (...) {
          firstvector_.pop_back();
          cout << "second vector update failed." << endl;
      }
  }

  int main() {
      std::vector<std::string> firstvector;
      std::vector<std::string> secondvector;
      std::string mystring("Hello world!");

      cout << "Calling updateVector " << endl;

      updateVector(firstvector, secondvector, mystring);

      cout << "first vector size is " << firstvector.size() << " second vector size is " << secondvector.size() << endl;

      cout << "Calling updateVector2 " << endl;

      updateVector2(firstvector, secondvector, mystring);

      cout << "first vector size is " << firstvector.size() << " second vector size is " << secondvector.size() << endl;

  }








  Now if the first vector fails to update in updateVector function then the second vector is never tried and if the second vector fails to update then the last item added to the first vector is removed and the exception passed up. Although this works it is not the best implementation, if we have more vectors to update then the nested try-block complexity increases. This is shown in the above programs output when the updateVector2 function throws an exception before updating the second vector. which results in the vector sizes being unchanged even though the first vector had already been updated.

What we really need to do is wrap the vector resources up in an object such that if either vector fails to update the object destructor is called and the update can be reversed. This procedure is generally referred to as scope guarding since the objects destructor will be called if it moves out of local scope. Let’s look at some code.

#include <vector>
#include <string>
#include <iostream>

using namespace std;

template<class TContainer>
class VecScopeGuard {
public:
    VecScopeGuard(TContainer* vecptr)
        : engaged_(true),vecptr_(vecptr) { //Assign vecptr and set guard to true.
    }

    ~VecScopeGuard() {
        if (engaged_) {
            //Remove last vector entry
            vecptr_->pop_back();
        }
    }
    void disengage() {
        engaged_ = false;
        //Vectors updated so release guard
    }
private:
    bool engaged_;
    TContainer* vecptr_;
};


int main()
{
    vector<string> firstvector;
    vector<string> secondvector;
    string mystring("Hello world!");
    try {
        firstvector.push_back(mystring);
        VecScopeGuard<vector<string>> guard1(&firstvector);
        secondvector.push_back(mystring);
        VecScopeGuard<vector<string>> guard2(&secondvector);

        guard1.disengage();
        guard2.disengage();
    }
    catch(...) {
        cout << "Caught error." << endl;
    }

    cout << "First use of scope guards ok, first vector size is  " << firstvector.size() << " second vector size is " << secondvector.size() << endl;

    //Clear vectors.
    firstvector.clear();
    secondvector.clear();

    try {
        firstvector.push_back(mystring);
        VecScopeGuard<std::vector<std::string>> guard1(&firstvector);
        std::bad_alloc excp;
        throw excp; //Replicate error updating second vector.
        secondvector.push_back(mystring);
        VecScopeGuard<std::vector<std::string>> guard2(&secondvector);
        guard1.disengage();
        guard2.disengage();
    }
    catch (std::bad_alloc e) {
        cout << "Caught exception " << endl;
        cout << "Second use of scope guards error, first vector size is  " << firstvector.size() << " second vector size is " << secondvector.size() << endl;
    }
}
So what does this do.? Well we define a template class called VecScopeGuard which takes a pointer to TContainer as a parameter in its constructor. We define a destructor for VecScopeGuard which checks if it is engaged and if so calls the std::vector method pop_back(). We define a disengage function which sets the bool engaged_ to false to stop the pop_back() function being called in the destructor. In the main method we create two std::string vectors and try to add an element to them. After the first vector has had an element added to it we create a VecScopeGuard object around it and then we add an element to the second vector. Should the second vector throw an exception during the push_back() function the exception handler will be invoked and the VecScopeGuard object around the first vector will move out of scope and hence it's destructor will be called. In the first try-catch block everything works and both vectors are updated with the string “Hello World” but in the second try-catch block we throw an exception to replicate what would happen if secondvector.push_back() failed. The exception handler is invoked and the console output confirms both vectors have the same size even though we had already added an element to the first vector successfully. Now this implementation is designed to only work with vectors as the VecScopeGuard destructor call the vector function pop_back(), a better generic implementation would avoid this and make it work for all objects and member functions in both the STL and user defined ones.

One such implementation is Andrei Alexandrescu's c++ library called Loki which can be found here. In this library he defines some template classes to be used for generic exception handling. In particular, he has implemented a ScopeGuard which allows you to roll back updates such as the above vectors in a more scalable solution. To use his code you would do something like the following.

void updateVector(std::vector<std::string>& firstvector,std::vector<std::string>& secondvector,std::string& newString){
    firstvector_.push_back(&newString);
    ScopeGuard guard = MakeObjGuard(&std::vector::pop_back,firstvector_);
    secondvector_.push_back(&newString);
    guard.Dismiss();
}
The ScopeGuard guard object will call pop_back on the firstvector when it's scope is exited by the function updateVector unless we call guard.Dismiss() first. This means if the secondvector_.push_back fails the update to the first vector will be rolled back. Using this functionality, you can make any number of transactional changes which require all-or-none to be successful. I will not delve into Andrei's library any more but I recommend readers use this as a resource for further learning.
