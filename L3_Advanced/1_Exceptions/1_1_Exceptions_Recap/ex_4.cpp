/*
we're going to show the concepts of a scope gad.

We have been working on demonstrating, updating two
vectors, where they both get updated, or none get updated,
and normal none transaction commit scenario.

*/


#include <iostream>
#include <vector>
#include <exception>

using namespace std;

template<class TContainer>
class VecScopeGuard {
public:
  VecScopeGuard(TContainer *vector)
    : engaged_(true), vecptr_(vecptr) // Assign vecptr and set guard to true.
    {}

    ~VecScopeGuard()
    {
      if(engaged_)
      {
        //Remove last vector entry
        vecptr_->pop_back();
      }
    }
    void disengage()
    {
      engaged_ = false;
      //Vectors updated so release guard
    }
private:
  bool engaged_;
  TContainer *vecptr_;
};


void updateVector(std::vector<std::string> &firstvector_, std::vector<std::string> &secondvector_, std::string newString)
{
  firstvector_.push_back(newString);
  try {
    secondvector_.push_back(newString);
  }
  catch(...) {
    firstvector_.pop_back();
    cout << "second vector update failed." << endl;
  }
}

void updateVector2(std::vector<std::string> &firstvector_, std::vector<std::string> &secondvector_, std::string newString) {
  firstvector_.push_back(newString);
  try {
    std::bad_alloc excep;
    throw excep;
    secondvector_.push_back(newString);
  }
  catch(...) {
    firstvector_.pop_back();
    cout << "second vector update failed." << endl;
  }
}


int main() {
  std::vector<std::string> firstvector;
  std::vector<std::string> secondvector;
  std::string mystring("Hello world!");

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

  cout << "first use of scope guards OK, first vector size is " firstvector.size() << ", second vector size is " secondvector.size() << endl;

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
  catch(std::bad_alloc e) {
    cout << "Caught exception " << endl;
    cout << "Second use of scope guards error, first vector size is " << firstvector.size() << " second vector size is " << secondvector.size() << endl;
  }
}
