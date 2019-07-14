/*
* How to handle a transaction roll back with resources.
* So the scenario is that we have two vectors
* that we want to update with the same valued element.
* And the first time we try to do this they will both succeed.
* The second time we will simulate the second vector update failing
* and the rollback on the first one.
*
* So, what kind of a scenario would this simulate?
* If, once again, your machine ran out of memory,
* when you try to update the second vector,
* you may get a bad alloc out of memory exception.
* And then we will print out the vector sizes, so
* we can confirm that they're the same.
*
* So this is a way of doing a transactional rollback
* on two vectors.
* And it's the brute force way.
*
* The downside to it is you have more than two vectors you're
* going to end up with a lot of extra code to handle this.
* And a lot of nested try catch statements,
* which is not the most elegant way of doing it.
* In the next demonstration I'll show you a more elegant way
* of ending this.
*/


#include <iostream>
#include <vector>
#include <exception>

using namespace std;

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

  cout << "calling updateVector " << endl;
  updateVector(firstvector, secondvector, mystring);
  cout << "first vector size is " << firstvector.size() << ", second vector size is " << secondvector.size() << endl;

  cout << "Calling updateVector2 " << endl;
  updateVector2(firstvector, secondvector, mystring);
  cout << "first vector size is " << firstvector.size() << ", second vector size is " << secondvector.size() << endl;
}
