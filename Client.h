#ifndef CLIENT_H //makrodefinicja straznika
#define CLIENT_H

#include <string>
using namespace std;

class Client {
private:
    string pesel;
    string name;
    string address;
public:
    Client(const string& pesel, const string& name, const string& address); // konstruktor
    string getPesel() const;
    string getName() const;
    string getAddress() const;
    void setName(const string& name);
    void setAddress(const string& address);
};

#endif // CLIENT_H
