#include <iostream>
#include "Database.h"
using namespace std;

void menu(Database& db) {
    int choice;
    do {
        cout << "1. Dodaj klienta" << endl;
        cout << "2. Dodaj konto" << endl;
        cout << "3. Dodaj transakcję" << endl;
        cout << "4. Wyświetl klienta" << endl;
        cout << "5. Wyświetl konto" << endl;
        cout << "6. Wyświetl transakcje" << endl;
        cout << "0. Wyjdź" << endl;
        cout << "Wybierz operację: ";
        cin >> choice;

        if (choice == 1) {
            string pesel, name, address, streetWithNumber, postalCodeAndCity;
            cout << "Podaj PESEL: ";
            cin >> pesel;
            cout << "Podaj imię i nazwisko: ";
            cin.ignore(); // Pomija znak nowej linii pozostały w buforze po wcześniejszym cin
            getline(cin, name);
            cout << "Podaj ulicę z numerem: ";
            getline(cin, streetWithNumber);
            cout << "Podaj kod pocztowy i miasto: ";
            getline(cin, postalCodeAndCity);
            address = streetWithNumber + " " + postalCodeAndCity;
            Client client(pesel, name,
                          address); // Tworzy nowy obiekt klasy Client, inicjalizując go podanymi wartościami pesel, name i address.

            // Sprawdzenie wyniku operacji dodawania klienta
            if (db.addClient(
                    client)) { // Wywołuje metodę addClient na obiekcie db (instancji klasy Database), przekazując nowo utworzony obiekt client. Metoda ta zapisuje dane klienta do pliku clients.txt.
                cout << "Klient został pomyślnie dodany." << endl;
            } else {
                cout << "Błąd: Nie udało się dodać klienta." << endl;
            }

    } else if (choice == 2) {
            string ownerPesel;
            cout << "Podaj PESEL właściciela: ";
            cin >> ownerPesel;

            if (!db.clientExists(ownerPesel)) {
                cout << "Błąd: Klient z podanym PESEL nie istnieje." << endl;
                continue; // Powrót do menu głównego
            }
            string accountNumber;
            double balance;
            cout << "Podaj numer konta: ";
            cin >> accountNumber;
            cout << "Podaj saldo: ";
            cin >> balance;
            Account account(accountNumber, ownerPesel, balance);
            if (db.addAccount(account)) {
                cout << "Konto zostało pomyślnie dodane." << endl;
            } else {
                cout << "Błąd: Nie udało się dodać konta." << endl;
            }

        } else if (choice == 3) {
            string transactionId, fromAccount, toAccount, date;
            double amount;
            cout << "Podaj ID transakcji: ";
            cin >> transactionId;
            cout << "Podaj numer konta nadawcy: ";
            cin >> fromAccount;
            cout << "Podaj numer konta odbiorcy: ";
            cin >> toAccount;
            cout << "Podaj kwotę: ";
            cin >> amount;
            cout << "Podaj datę (dd.mm.rrrr): ";
            cin >> date;
            Transaction transaction(transactionId, fromAccount, toAccount, amount, date);
            db.addTransaction(transaction);
        } else if (choice == 4) {
            string pesel;
            cout << "Podaj PESEL: ";
            cin >> pesel;
            Client client = db.getClient(pesel);
            cout << "PESEL: " << client.getPesel() << endl;
            cout << "Imię i nazwisko: " << client.getName() << endl;
            cout << "Adres: " << client.getAddress() << endl;
        } else if (choice == 5) {
            string pesel;
            cout << "Podaj PESEL klienta: ";
            cin >> pesel;
            // Wyszukaj klienta o podanym PESEL
            Client client = db.getClient(pesel);
            if (client.getPesel() != "") {
                // Jeśli klient został znaleziony, wyświetl informacje o koncie
                Account account = db.getAccountByPesel(pesel);
                if (account.getAccountNumber() != "") {
                    cout << "Numer konta: " << account.getAccountNumber() << endl;
                    cout << "PESEL właściciela: " << account.getOwnerPesel() << endl;
                    cout << "Saldo: " << account.getBalance() << endl;
                    vector<Transaction> transactions = db.getTransactions(account.getAccountNumber());
                    if (!transactions.empty()) {
                        cout << "Ostatnie transakcje:" << endl;
                        for (const auto& transaction : transactions) {
                            cout << "ID transakcji: " << transaction.getTransactionId() << endl;
                            cout << "Od: " << transaction.getFromAccount() << endl;
                            cout << "Do: " << transaction.getToAccount() << endl;
                            cout << "Kwota: " << transaction.getAmount() << endl;
                            cout << "Data: " << transaction.getDate() << endl;
                            cout << "-----------------" << endl;
                        }
                    } else {
                        cout << "Brak transakcji dla tego konta." << endl;
                    }
                } else {
                    cout << "Konto dla podanego PESEL nie istnieje." << endl;
                }
            } else {
                cout << "Klient o podanym PESEL nie istnieje." << endl;
            }
        }
        else if (choice == 6) {
            string accountNumber;
            cout << "Podaj numer konta: ";
            cin >> accountNumber;
            vector<Transaction> transactions = db.getTransactions(accountNumber);
            for (const auto& transaction : transactions) {
                cout << "ID transakcji: " << transaction.getTransactionId() << endl;
                cout << "Od: " << transaction.getFromAccount() << endl;
                cout << "Do: " << transaction.getToAccount() << endl;
                cout << "Kwota: " << transaction.getAmount() << endl;
                cout << "Data: " << transaction.getDate() << endl;
                cout << "-----------------" << endl;
            }
        }
    } while (choice != 0);
}

int main() {
    Database db;
    menu(db);
    return 0;
}
