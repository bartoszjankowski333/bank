#include "Account.h"

Account::Account(const string& accountNumber, const string& ownerPesel, double balance)
        : accountNumber(accountNumber), ownerPesel(ownerPesel), balance(balance) {}

string Account::getAccountNumber() const {
    return accountNumber;
}

string Account::getOwnerPesel() const {
    return ownerPesel;
}

double Account::getBalance() const {
    return balance;
}

void Account::deposit(double amount) {
    balance += amount;
}

bool Account::withdraw(double amount) {
    if (amount > balance) {
        return false;
    }
    balance -= amount;
    return true;
}
