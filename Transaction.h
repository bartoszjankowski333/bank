#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
using namespace std;

class Transaction {
private:
    string transactionId;
    string fromAccount;
    string toAccount;
    double amount;
    string date;
public:
    Transaction(const string& transactionId, const string& fromAccount, const string& toAccount, double amount, const string& date);
    string getTransactionId() const;
    string getFromAccount() const;
    string getToAccount() const;
    double getAmount() const;
    string getDate() const;
};

#endif // TRANSACTION_H
