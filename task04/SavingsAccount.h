/* Assignment C++: 2
   Author: Yarin Oziel, ID: 319149878
   Author: Itamar Meir, ID: 208536888
*/ 
#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H
#include "Account.h"
#include <chrono>
#include <thread>

class SavingsAccount : public Account
{
   private:
      double annualInterestRate;
      std::chrono::steady_clock::time_point lastTransactionTime;
   
   public:
      SavingsAccount(const std::string& number, const std::string& holder, const double initialBalance, const double annualRate);
      ~SavingsAccount(){};

      void deposit(const double amount) override;
      void withdraw(const double amount) override;
      void addInterest();

      void print(ostream& os) override{
         this->addInterest(); // add the interest
         Account::print(os);
      };

};


#endif // SAVINGS_ACCOUNT_H