// #include "stdafx.h"
#include "SavingsAccount.h"
#include <iostream>

void freezeMe(Freezable &f)
{
  //NOTE: takes a VIRTUAL INTERFACE
  // We don't know what type of object f referes to.
  // All we know is that it implements "Freezable".
  f.freeze();
}

int main()
{
  SavingsAccount acc(1000, 2.5);

  std::cout << "Terms and conditions: " << acc.getTermsAndConditions() << std::endl;
  std::cout << "Guarantee limit: " << acc.getGuaranteedLimit() << std::endl;

  acc.deposit(100);
  acc.deposit(200);
  acc.withdraw(50);
  acc.earnInterest();

  freezeMe(acc);

  acc.deposit(1000);
  acc.deposit(2000);
  acc.withdraw(500);
  acc.earnInterest();

  acc.unfreeze();

  acc.deposit(10000);
  acc.deposit(20000);
  acc.withdraw(5000);
  acc.earnInterest();

  return 0;
}
