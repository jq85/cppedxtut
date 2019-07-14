#pragma once

#include "BankAccount.h"
#include "Freezable.h"
#include "Loggable.h"

// class BankAccount;
// class Freezable;
// class Loggable;

#include <list>


//NOTE: MULTIPLE INHERITANCE (of interfaces in this case), is private by default
class SavingsAccount : public BankAccount, public Freezable, public Loggable
{
private:
  double interestRate;
  bool frozen;

public:
  SavingsAccount(double initialBalance, double interestRate = 0.0);
  virtual ~SavingsAccount();

  void earnInterest();

  virtual void deposit(double amount);
  virtual void withdraw(double amount);

  // Mandatory to implement pure virtual functions from BankAccount class.
  virtual std::string getTermsAndConditions();
  virtual double getGuaranteedLimit();

  // Mandatory to implement pure virtual functions from Freezable class.
  virtual void freeze();
  virtual void unfreeze();

  // Mandatory to implement pure virtual functions from Loggable class.
  virtual void log(const std::string &message) const;
};
