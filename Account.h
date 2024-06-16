#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
using namespace std;

class Account {
private:
    string accountNumber;
    string ownerPesel;
    double balance;
public:
    Account(const string& accountNumber, const string& ownerPesel, double balance = 0.0);
    string getAccountNumber() const;
    string getOwnerPesel() const;
    double getBalance() const;
    void deposit(double amount);
    bool withdraw(double amount);
};

#endif // ACCOUNT_H
