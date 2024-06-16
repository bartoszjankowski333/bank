#include "Transaction.h"

Transaction::Transaction(const string& transactionId, const string& fromAccount, const string& toAccount, double amount, const string& date)
        : transactionId(transactionId), fromAccount(fromAccount), toAccount(toAccount), amount(amount), date(date) {}

string Transaction::getTransactionId() const {
    return transactionId;
}

string Transaction::getFromAccount() const {
    return fromAccount;
}

string Transaction::getToAccount() const {
    return toAccount;
}

double Transaction::getAmount() const {
    return amount;
}

string Transaction::getDate() const {
    return date;
}
