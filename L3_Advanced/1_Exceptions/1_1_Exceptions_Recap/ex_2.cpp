#include <iostream>

using namespace std;

int main()
{
  // FORCE A INT TYPE EXCEPTION
  try {
    throw 20;
  }
  catch (int exc) { cout << "int exception." << endl; }
  catch (double exc) { cout << "double exception." << endl; }
  catch (...) { cout << "All other exception types." << endl; }//NOTE: default catch handler

  // FORCE A DOUBLE TYPE EXCEPTION
  try {
    throw 20.0;
  }
  catch (int exc) { cout << "int exception." << endl; }
  catch (double exc) { cout << "double exception." << endl; }
  catch (...) { cout << "All other exception types." << endl; }//NOTE: default catch handler

  // FORCE A BOOLEAN TYPE EXCEPTION
  try {
    throw true;
  }
  catch (int exc) { cout << "int exception." << endl; }
  catch (double exc) { cout << "double exception." << endl; }
  catch (...) { cout << "All other exception types." << endl; }//NOTE: default catch handler


  try {
    try {
      // Do something here that causes an exception
      throw 10;
    }
    catch (int numb) {
      cout << "Caught int exception." << endl;
      throw;
    }
  }
  catch(...) {
    cout << "An error occurred." << endl;
  }

}
