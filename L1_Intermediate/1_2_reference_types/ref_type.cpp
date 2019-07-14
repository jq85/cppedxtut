#include <iostream>

using namespace std;

int main()
{
  //create an integer variable called num and assign it a value of 3.
  int num = 3;
  //declare a reference called refNum.
  int &refNum = num;

  cout << "num contains " << num << endl;
  cout << "refNum contains " << refNum << endl;

  refNum++;    // increment refNum by 1
  //The & character tells us this is a reference value. Note that we immediately assign it to the num variable.
  //This binds refNum to num.
  //This reference cannot   be reassigned later in program code.
  // int &refNum2;//WARNING: causes an error because it has not been initialized.
  int &refNum2 = num;
  //outputs the value 3, which is correct because refNum is an alias or reference to num, which holds the value 3.
  cout << refNum << endl;

  cout << "num contains " << num << endl;
  cout << "refNum contains " << refNum << endl;
  //Outputs the memory address of num and refNum to show that they both point to the same memory location.
  //As a result, any changes made to refNum affect num.
  cout << "refNum is located at " << &refNum << " and num is located at " << &num << endl;

  return 0;
}
