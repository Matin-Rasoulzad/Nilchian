//
// Created by Matin on 5/22/2024.
//
#include "Person.h"

Person::Person(string name, string id, Address address) {
    if(!isValid(id)){
        cout << "Invalid Id!\n";
        exit(1);
    }
    this->name = name;
    this->id = id;
    this->address = address;
}

Person::Person(Person &obj) {
    this->name = obj.name;
    this->id = obj.id;
    this->address = obj.address;
}

void Person::setPerson(std::string name, std::string id, Address address) {
    this->name = name;
    this->id = id;
    this->address = address;
}

string Person::getPerson() {
    return ("Name: " + name + ", " + "ID: " + id + "\n" + address.getAddress());
}


// Overloaded << operator
ostream &operator<<(ostream &os, const Person &person) {
    os << "Name: " << person.name << ", " << "ID: " << person.id << "\n" << person.address.getAddress();
    return os;
}

// Overloaded >> operator
istream &operator>>(istream &is, Person &person) {
    cout << "Enter Name: ";
    is >> person.name;
    cout << "Enter ID: ";
    is >> person.id;
    is >> person.address;
    return is;
}

Person &Person::operator=(const Person &other) {
    if (this == &other)
        return *this;
    name = other.name;
    id = other.id;
    address = other.address;
    return *this;
}

bool Person::isValid(string id) {
    //Checking lenght
    if (id.length() < 8 || id.length() > 10) return false;

    //Checking Year
    string stringYear = id.substr(0, 2);
    int year = stoi(stringYear);
    if (year < 84 || year > 99) return false;

    //Checking Numeric Value
    for (size_t i = 2; i < id.length() - 5; ++i) {
        if (isdigit(id[i]))
            return false;
    }
    for (size_t i = id.length() - 5; i < id.length(); ++i) {
        int num = id[i] - '0';
        if (num >= 4 && num <= 6)
            return false;
    }
    return true;
}

