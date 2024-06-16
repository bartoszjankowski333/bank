#ifndef DATABASE_H
#define DATABASE_H

#include <vector>
#include <string>
#include "Client.h"
#include "Account.h"
#include "Transaction.h"
using namespace std;

class Database {
public:
    Database();
    bool addClient(const Client& client);
    bool addAccount(const Account& account);
    bool clientExists(const string& pesel);
    bool addTransaction(const Transaction& transaction);
    Client getClient(const string& pesel);
    Account getAccount(const string& accountNumber);
    vector<Transaction> getTransactions(const string& accountNumber);
    Account getAccountByPesel(const string& pesel); // Nowa metoda
private:
    const string clientsFile = "clients.txt";
    const string accountsFile = "accounts.txt";
    const string transactionsFile = "transactions.txt";
};

#endif // DATABASE_H
