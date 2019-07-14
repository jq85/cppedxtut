# Handling Exceptions
======================

## STRATEGIES FOR HANDLING EXCEPTIONS
-------------------------------------
You should always try to use the in built C++ throw and catch exception support.
When an exception is encountered the program should either:
  - survive the exception and continue to process events,
  - or shut down gracefully.

COLLECT INFO
The relevant actors should be notified i.e. the user or developer or system administrator etc.
If the exception is caught enough information should be made available so it can be reproduced, diagnosed and fixed.
The strategy should not make the code base cluttered or un-maintainable and un-scalable.

GRACEFUL RUN/SHUT DOWN
When an exception is caught it should be handled so as the application can continue as though nothing happened,
or if it is not possible to continue at this point then the application should shut down gracefully.

FREE RESOURCES
Any resources that may have been opened or used when the exception is thrown by the program need to be closed or freed by the exception handler,
or if it's not possible to continue all resources should be closed or freed on application shut down.

NOTIFY, REPRODUCE ERROR
When an exception occurs the user needs to be notified via the user interface.
The administrators and developers of the application should be notified via logging to a log file with enough information logged to be able to reproduce the error.

3rd PARTY EXCEPTIONS, COMPATIBILITY
If the application uses third party library's such as data base drivers which can throw their own exception types,
then you should catch these exceptions and throw types your application understands;
this way if you change databases then your application won’t break when different database driver throw exceptions.

MAIN 3 TYPES OF ERRORS
Errors can be separated into 3 main areas:
 - USER ERRORS: such as passing invalid arguments to a command line application.
   User errors can be detected by validating parameters and then returning an error message.

 - THIRD PARTY ERRORS: such as a database or other service.
   Third party errors require the developers to know something about the responses from the underlying technology so as to decide what action to take,
   for instance a database request may fail and you might be able to retry the request against a mirrored database.

 - INTERNAL ERRORS: in the application itself such as bugs.
   Internal errors can be passively propagated up the call stack or intentionally passed.
   Prior to c++11 it was possible to use exception specifications to indicate if a function was going to throw an exception or not like so.



OLD C++ VS C++11
  void myfunction() throw();  //Does not throw an exception
  void myfunction() throw(...);  //Throws an exception
  void myfunction() throw(mytype);  //Throws exception of type mytype.

In C++11 this has been replaced with noexcept like so

  void myfunction() noexcept;   //Throws an exception equal to noexcept(true)
  void myfunction() noexcept(true/false);   //Throws an exception depending on boolean true/false



EXAMPLE
This is an example of passively propagating exceptions,
to intentionally propagate an exception we would use the throw keyword within the function.

When throwing an exception you should:
  - provide the error
  - provide the location it happened
  - append info every time you catch this and re throw it up the call stack.



For instance we could derive from std::exception like so
Using something like below will allow you to pass exception information up the call stack,
but the below implementation will not work if the machine has memory exhaustion as the push_back vector function will throw a bad_alloc error if it tries to allocate memory for the vector.
This shows that you need to be aware of the STL exceptions when using the STL in user defined objects.

    #include <string>
    #include <iostream>
    #include <vector>
    #include <exception>

    using namespace std;

    struct errorinfo {
        int id;
        int locationId;
        int level;
        std::string description;
        std::string reason;
    };

    class myexception : public std::exception {

    public:

        myexception(const std::string& message) : msg(message) {

        }

        virtual char const* what() const {
            return msg.c_str();
        }

        virtual ~myexception() throw () {
            errorlist.clear();
        }

        void adderror(errorinfo info) throw(bad_alloc) {
            //try {
                errorlist.push_back(info);
            //}
            //catch (...) {
                //push_back has thrown an error.
            //    cout << "Bad alloc in adderror function." << endl;
            //}
        }

        vector<errorinfo>::iterator begin() { return errorlist.begin(); }
        vector<errorinfo>::iterator end() { return errorlist.end(); }

    protected:
        std::string msg;
        std::vector<errorinfo> errorlist;
    };

    int main() {
        try {
            try {
                try {
                    myexception myex("myexception object thrown.");  //Create myexception object
                    throw myex;   //Throw myexception object
                }
                catch (myexception e) {    //Catch myexception object
                    errorinfo firstinfo;    //Create errorinfo struct
                    firstinfo.reason = "level 1 error";
                    firstinfo.id = 1;
                    firstinfo.locationId = 0;
                    firstinfo.level = 0;
                    firstinfo.description = "First level exception thrown.";
                    try {
                        e.adderror(firstinfo);  //Add errorinfo struct to myexception object
                    }
                    catch (bad_alloc) {
                        cout << "Out of memory myexception.adderror bad_alloc." << endl;
                    }
                    throw e;   //Throw myexceptionobject up call stack.
                }
            }
            catch (myexception e) {
                errorinfo secondinfo;
                secondinfo.reason = "level 2 error";
                secondinfo.id = 2;
                secondinfo.locationId = 1;
                secondinfo.level = 2;
                secondinfo.description = "Second level exception thrown.";
                try {
                    e.adderror(secondinfo);
                }
                catch (bad_alloc) {
                    cout << "Out of memory myexception.adderror bad_alloc." << endl;
                }
                throw e;
            }
        }
        catch (myexception e) {
            //Print out errorinfo structs in myexception object
            for (std::vector<errorinfo>::iterator iter = e.begin(); iter != e.end(); ++iter) {
                errorinfo next = *iter;
                cout << next.reason << " " << next.id << " " << next.locationId << " " << next.level << " " << next.description << endl;
            }
        }

    }
