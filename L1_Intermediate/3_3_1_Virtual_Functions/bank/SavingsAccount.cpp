// #include "stdafx.h"
#include "SavingsAccount.h"
#include <iostream>

/*
* So SavingsAccount implements:
*   - its own behavior
*   - implemented methods that it chose to, like deposit() and withdraw(),
*   - implemented methods that it had to, by virtue of the pure virtual functions in the base classes.
*/

SavingsAccount::SavingsAccount(double initialBalance, double interestRate)
  : BankAccount{initialBalance}, interestRate{interestRate}, frozen{false}
{
  
}

SavingsAccount::~SavingsAccount()
{}


void SavingsAccount::earnInterest()
{
  if(!frozen)
  {
    double interest = balance * (interestRate / 100);
    deposit(interest);//amount of extra money to be added to our bank balance.
  }
}


void SavingsAccount::deposit(double amount)
{
  if(!frozen)
  {
    BankAccount::deposit(amount);
    //This is the log message that we've implemented from the interface
    log("Deposit: " + std::to_string(amount));
  }
}


void SavingsAccount::withdraw(double amount)
{
  if((!frozen) && (amount <= balance))
  {
    BankAccount::withdraw(amount);
    log("Withdrawal: " + std::to_string(amount));
  }
}


std::string SavingsAccount::getTermsAndConditions()
{
  return "This is a savings account. You cannot go overdrawn. You earn interest.";
}


double SavingsAccount::getGuaranteedLimit()
{
  return 75000;
}


void SavingsAccount::freeze()
{
  frozen = true;//NOTE: no use of 'this->' because of it is virtual (?)
}


void SavingsAccount::unfreeze()
{
  frozen = false;//NOTE: no use of 'this->' because of it is virtual (?)
}


void SavingsAccount::log(const std::string &message) const
{
  std::cout << message << std::endl;
}
