#pragma once

#include <string>

class BankAccount
{
protected:
  double balance;

public:
  BankAccount(double initialBalance);
  virtual ~BankAccount();

  double getBalance() const;

  virtual void deposit(double amount);
  virtual void withdraw(double amount);

  //NOTE: "= 0" makes them PURE VIRTUAL, i.e. not implemented in the base class,
  // so they must be overriden in derived classes.
  virtual std::string getTermsAndConditions() = 0;
  virtual double getGaranteedLimit() = 0;
};
