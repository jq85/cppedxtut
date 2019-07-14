#include "MyMath.h"
#include <iostream>

using namespace std;

MyMath::Math::Math()
{

}

MyMath::Math::~Math()
{

}

int MyMath::Math::pow(int base, int exp)
{
  cout << endl << "in MyMath::Math::pow" << endl;

  int result = 1;
  if(exp != 0)
  {
    for(int i = 0; i < exp; i++)
    {
      result = result * base;
    }
  }
  else
  {
    cout << "only positive numbers accepted for the exponent" << endl;
    result = 0;
  }
  return result;
}
