//
// Created by Matin on 5/22/2024.
//

#ifndef ADDRESS_ADDRESS_H
#define ADDRESS_ADDRESS_H
#include "string"
#include "iostream"
using namespace std;
class Address {
private:
    string country , city , street;
public:
    Address(string country ,string city ,string street);
    string getAddress();
    void setAddress(string country, string city, string street);
    friend ostream& operator<<(ostream& os, const Address& address);
    friend istream& operator>>(istream& is, Address& address);
};


#endif //ADDRESS_ADDRESS_H
