#include "Database.h"
#include <fstream>
#include <sstream>

// Helper function to split a string by a delimiter
vector<string> split(const string& str, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(str);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

Database::Database() {}

bool Database::addClient(const Client& client) {
    ofstream file(clientsFile, ios::app); // Otwiera plik accounts.txt w trybie dodawania (ios::app), co oznacza, że nowe dane będą dopisywane na końcu pliku, bez nadpisywania istniejących danych.
    if (file.is_open()) {
        file << client.getPesel() << ',' << client.getName() << ',' << client.getAddress() << endl; // Zapisuje numer konta, numer PESEL właściciela oraz saldo konta do pliku, oddzielając te dane przecinkami.
        file.close();
        return true;
    }
    return false;
}

bool Database::addAccount(const Account& account) {
    ofstream file(accountsFile, ios::app);
    if (file.is_open()) {
        file << account.getAccountNumber() << ',' << account.getOwnerPesel() << ',' << account.getBalance() << endl;
        file.close();
        return true;
    }
    return false;
}

bool Database::clientExists(const string& pesel) {
    ifstream file(clientsFile);
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string filePesel;
        getline(ss, filePesel, ',');
        if (filePesel == pesel) {
            return true; // Klient istnieje
        }
    }
    return false; // Klient nie istnieje
}

bool Database::addTransaction(const Transaction& transaction) {
    ofstream file(transactionsFile, ios::app);
    if (file.is_open()) {
        file << transaction.getTransactionId() << ',' << transaction.getFromAccount() << ',' << transaction.getToAccount() << ',' << transaction.getAmount() << ',' << transaction.getDate() << endl;
        file.close();
        return true;
    }
    return false;
}

Client Database::getClient(const string& pesel) {
    ifstream file(clientsFile);
    string line;
    while (getline(file, line)) {
        vector<string> tokens = split(line, ',');
        if (tokens[0] == pesel) {
            return Client(tokens[0], tokens[1], tokens[2]);
        }
    }
    return Client("", "", "");
}

Account Database::getAccount(const string& accountNumber) {
    ifstream file(accountsFile);
    string line;
    while (getline(file, line)) {
        vector<string> tokens = split(line, ',');
        if (tokens[0] == accountNumber) {
            return Account(tokens[0], tokens[1], stod(tokens[2]));
        }
    }
    return Account("", "", 0.0);
}

vector<Transaction> Database::getTransactions(const string& accountNumber) {
    vector<Transaction> transactions;
    ifstream file(transactionsFile);
    string line;
    while (getline(file, line)) {
        vector<string> tokens = split(line, ',');
        if (tokens[1] == accountNumber || tokens[2] == accountNumber) {
            transactions.push_back(Transaction(tokens[0], tokens[1], tokens[2], stod(tokens[3]), tokens[4]));
        }
    }
    return transactions;
}

Account Database::getAccountByPesel(const string& pesel) {
    ifstream file(accountsFile);
    string line;
    while (getline(file, line)) {
        vector<string> tokens = split(line, ',');
        if (tokens[1] == pesel) {
            return Account(tokens[0], tokens[1], stod(tokens[2]));
        }
    }
    return Account("", "", 0.0);
}
