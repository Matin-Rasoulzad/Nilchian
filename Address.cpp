//
// Created by Matin on 5/22/2024.
//

#include "Address.h"

Address::Address() : country(""), city(""), street("") {}
Address::Address(string country, string city, string street) {
    this->city = city;
    this->country = country;
    this->street = street;
}

void Address::setAddress(string country, string city, string street) {
    this->city = city;
    this->country = country;
    this->street = street;
}

string Address::getAddress() const {
    return (country + ", " + city + ", " + street + "\n");
}


// Overloaded << operator
ostream &operator<<(ostream &os, const Address &address) {
    os << address.country << ", " << address.city << ", " << address.street << "\n";
    return os;
}

// Overloaded >> operator
istream &operator>>(istream &is, Address &address) {
    cout << "Enter country: ";
    is >> address.country;
    cout << "Enter city: ";
    is >> address.city;
    cout << "Enter street: ";
    is >> address.street;
    return is;
}

