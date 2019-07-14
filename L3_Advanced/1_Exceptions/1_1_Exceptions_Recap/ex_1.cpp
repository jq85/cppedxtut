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
