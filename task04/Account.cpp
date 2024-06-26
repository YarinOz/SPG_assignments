/* Assignment C++: 2
   Author: Yarin Oziel, ID: 319149878
   Author: Itamar Meir, ID: 208536888
*/ 

#include "Account.h"

Account::Account(const std::string& number, const std::string& holder, double initialBalance)
: Balance(initialBalance), accountNumber(number), accountHolderName(holder){}
