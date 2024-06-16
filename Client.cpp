#include "Client.h"

Client::Client(const string& pesel, const string& name, const string& address)
        : pesel(pesel), name(name), address(address) {} // Inicjalizuje pola pesel, name i address przy użyciu listy inicjalizacyjnej.

string Client::getPesel() const {
    return pesel;
}

string Client::getName() const {
    return name;
}

string Client::getAddress() const {
    return address;
}

void Client::setName(const string& name) {
    this->name = name;
}

void Client::setAddress(const string& address) {
    this->address = address;
}
