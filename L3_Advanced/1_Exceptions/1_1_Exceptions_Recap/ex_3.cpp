#include <iostream>
#include <exception>

using namespace std;

class throwexception {
public:
  throwexception();
  ~throwexception();
};

throwexception::throwexception(void) {
  cout << "throwexception object constructed" << endl;
}

throwexception::~throwexception(void) {
  cout << "throwexception destructor called." << endl;
}

int main()
{
  try {
    throwexception texc;
    cout << "Throwing exception will cause termination of program." << endl;
    throw 7;
  }
  catch(...) {
    cout << "Main exception caught" << endl;
  }
}
